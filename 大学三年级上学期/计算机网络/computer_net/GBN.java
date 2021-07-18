package computer_net;

//import java.awt.List;//导错包导致38行一直报错:类型 List 不是通用的；不能使用参数 <ByteArrayOutputStream> 将它参数化
import java.util.List;//这才是正确的应该导入的包
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.net.*;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketTimeoutException;
import java.net.UnknownHostException;
import java.util.LinkedList;

class GBN {
	//获取到本机的InetAddress
	private InetAddress host;
	//目标端口和本机端口
	private int targetPort, ownPort;
	//若此处改窗口大小为1，则为停等协议
	private int WindowSize = 16;
	//最大发送时间，最大接收时间，一个数据包的超时时间
	private final int sendMaxTime = 2,receiveMaxTime = 4,endTime=5; 
	//起始base值
	private long base = 0;
	//按照模N运算模拟丢包，N即Lossgap
	private final int Lossgap = 100;
	//对GBN中成员变量进行赋值A
	GBN(String host, int targetPort, int ownPort) throws UnknownHostException {
			//this关键字调用类中成员变量ownPort
			this.ownPort = ownPort;
			//确定主机的IP地址
			this.host = InetAddress.getByName(host);
			//this关键字调用类中成员变量targetPort
			this.targetPort = targetPort;
	}
/**
  *向主机目的地址处传输数据相关功能
 */
//send功能
void send(byte[] content) throws IOException {
	//
	int sendIndex = 0, length;
	//自行设计数据包最大字节数
	final int MAX_LENGTH = 1024;
	//用于UDP类DatagramSocket，表示接受或发送数据报的套接字，此处先建立套接字<DatagramSocket>
	DatagramSocket datagramSocket = new DatagramSocket(ownPort);
	//滑动窗口缓存，采用链表的数据结构，因为数据包需要按序标识并存下，这样才能实现重传
	List<ByteArrayOutputStream> datagramBuffer = new LinkedList<>(); 
	//实例化一个Integer类的对象timer，并给该对象赋值为0（计时器）
	Integer timer = 0;
	//自行设计序列号
	long sendSeq = base;
	do {
		//直到窗口开始滑动
		while (sendIndex < content.length && sendSeq < 256 && datagramBuffer.size()<WindowSize) {
			//向滑窗缓存中加入byte型数据
			datagramBuffer.add(new ByteArrayOutputStream());
			//若数据部分字节数未超过限定的最大值，则不变；若超过，就取限定的最大值
			length = content.length - sendIndex < MAX_LENGTH ? content.length - sendIndex : MAX_LENGTH;
			//构造数据帧
			ByteArrayOutputStream oneSend = new ByteArrayOutputStream();
			//初始化byte数组
			byte[] temp = new byte[1];
			//
			temp[0] = new Long(sendSeq).byteValue();
			//从temp中向oneSend写入从0开始处一字节的数据
			oneSend.write(temp, 0, 1);
			//从content中向oneSend写入从sendIndex开始处length字节的数据
			oneSend.write(content, sendIndex, length);
			//DatagramPacket表示存放数据的数据报，此句表示向host地址targetPort端口处发送oneSend.size()长度的oneSend.toByteArray()
			DatagramPacket datagramPacket = new DatagramPacket(oneSend.toByteArray(), oneSend.size(), host, targetPort);
			//从datagramSocket发送datagramPacket
			datagramSocket.send(datagramPacket);
			//向滑窗缓存中sendSeq-base的位置写入content中从sendIndex开始处length字节的数据
			datagramBuffer.get((int) (sendSeq - base)).write(content, sendIndex, length);
			//后移length，循环用
			sendIndex += length;
			//“输出的数据包序号为sendSeq”
			System.out.println("send the datagram seq: " +sendSeq);
			//序号+1，循环用
			sendSeq++;
		}
		//倒计时函数实现1秒倒计时
		datagramSocket.setSoTimeout(1000);
		//创建一个接受ACK的数据包
		DatagramPacket receivePacket;
		try{//从base开始接收ACK receive ACKs for base
			while (true) {
				//1500字节的recv字节数组
				byte[] recv = new byte[1500];
				//存放recv.length长的recv的数据报
				receivePacket = new DatagramPacket(recv, recv.length);
				//套接字开始接收数据包，当接收到时，receivePacket填满为接收到的数据
				datagramSocket.receive(receivePacket);
				//与11111111按位与，结果化为int型赋予ack，这一步是为了实现接收方按序接收数组
				int ack = (int) ((recv[0] & 0x0FF));
				//如果接收到了第一个，就继续接收第二个，并顺便清空缓存
				if (ack == base) {
					base++;
					datagramBuffer.remove(0);
					break;
				}
			}
		//超时功能
		} catch (SocketTimeoutException e) {
			timer++;
		}
			//如果超出设定的超时时间
			if ( timer> this.sendMaxTime) { 
				// 重发所有没有收到ACK（超时）的数据报
				for (int i = 0; i<datagramBuffer.size();i++) {
					ByteArrayOutputStream resender =  new ByteArrayOutputStream();
					byte[] temp = new byte[1];
					temp[0] = new Long(i + base).byteValue();
					resender.write(temp, 0, 1);
					resender.write(datagramBuffer.get(i).toByteArray(), 0, datagramBuffer.get(i).size());
					DatagramPacket datagramPacket = new DatagramPacket(resender.toByteArray(), resender.size(), host, targetPort);
					datagramSocket.send(datagramPacket);
					System.err.println("resend the datagram's seq: "+ (i + base));
			}
				//重置timer
				timer = 0;
		//base每到256，就将base和sendSeq重置
		if (base >= 256) {
			base = base - 256;
			sendSeq = sendSeq - 256;
			} 
		}
		//直到数据全部传输完成
		}while (sendIndex < content.length || datagramBuffer.size() !=0) ;
		//关闭套接字
		datagramSocket.close();
	}
	
	/**
	  * 接收主机目的地址处的数据相关功能
	 */
	//receive
	ByteArrayOutputStream receive() throws IOException {
		//用于 used to simulate datagram loss
		int count = 1,time=0; 
		long nowseq = 0;
		//存储接收的 store the received content
		ByteArrayOutputStream result = new ByteArrayOutputStream();
		//接收数据报和发送ACK的UDP套接字  UDP socket to receive datagram and send ACKs		
		DatagramSocket datagramSocket = new DatagramSocket(ownPort); 
		//一个暂时的数据报 one temp datagram packet
		DatagramPacket receivePacket;
		//
		datagramSocket.setSoTimeout(endTime*1000);
		while (true) {
			//接收一个数据报并且返回ACK
			try {
				byte[] recv = new byte[1500];
				receivePacket = new DatagramPacket(recv, recv.length, host, targetPort);
				datagramSocket.receive(receivePacket);
			//当模N为0时，人为产生一个丢包
			if (count % Lossgap != 0) {
				long seq = recv[0] & 0x0FF;
				if (seq == nowseq) {
					//accept
					nowseq++;
					if (nowseq>=256)nowseq=0;
					//写在上write to upper
					result.write(recv, 1, receivePacket.getLength()-1);
					//发送ACK send ACK
						recv = new byte[1];
						recv[0] = new Long(seq).byteValue();
						receivePacket = new DatagramPacket(recv, recv. length, host, targetPort);
						datagramSocket.send(receivePacket);
						System.out.println("receive datagram seq: " + seq);
						datagramSocket.setSoTimeout(endTime*1000);
					}//else discard
					}
				}catch (SocketTimeoutException e) {
					break;
			}
			//datagramSocket.setSoTimeout(endTime);
			count++;
		}
		datagramSocket.close();
		return result;
	}
}