package ChatRoom;

import java.awt.Color;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextArea;

public class groupDialogFrame{
	int port_num=8888;
	String username;
	String groupname;
	InetAddress inetaddress;
	MulticastSocket multicastsocket;
	
	groupDialogFrame(group g,String user_name,JButton enter_but){
		groupname=g.group_name;
		username=user_name;
		try{
			/*
			 * 设置该成员加入IP地址为224.0.0.1的组，同时监听8888号端口;
			 */
			multicastsocket=new MulticastSocket(port_num);
			inetaddress=g.group_inetAddress;
			multicastsocket.joinGroup(inetaddress);
		}catch(Exception e){
			System.out.println(e);
		}
		dialog_frame(enter_but);
	}
	void dialog_frame(JButton enter_but){
		//设置聊天窗口
		JFrame frame=new JFrame("群聊");
		frame.setBounds(500,300,500,500);
		frame.setLayout(null);
		//设置聊天框标签
		JLabel label=new JLabel("");
		label.setBounds(0, 0, 520, 5);
		frame.add(label);
		//设置聊天框
		JTextArea text_area=new JTextArea();
		text_area.setBounds(0, 0, 520, 280);
		frame.add(text_area);
		//设置输入标签
		JLabel input_l=new JLabel("  输入框");
		input_l.setBounds(0,295,510,15);
		frame.add(input_l);
		//设置输入框
		JTextArea input_t=new JTextArea();
		input_t.setBounds(0, 320, 510, 103);
		frame.add(input_t);
		//设置退出按钮
		JButton exit_but=new JButton("退出");
		exit_but.setBounds(0,423,250,40);
		frame.add(exit_but);
		//设置发送按钮
		JButton send_but=new JButton("发送");
		send_but.setBounds(250,423,250,40);
		frame.add(send_but);
		frame.setVisible(true);
		frame.setResizable(false);	
		//退出按钮
		exit_but.addMouseListener(new MouseListener(){
			public void mouseClicked(MouseEvent arg0){
				frame.dispose();
				enter_but.setEnabled(true);
			}

			@Override
			public void mouseEntered(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void mouseExited(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void mousePressed(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}
		});
		//群组群聊发送按钮
		send_but.addMouseListener(new MouseListener(){

			@Override
			//点击发送按钮时，将用户名以及输入框中的文本作为数据组播给群成员，然后将输入框中的文本清空
			public void mouseClicked(MouseEvent arg0) {
				byte[] send_message;
				DatagramPacket send_packet;
				try{			
					send_message=(username+":"+input_t.getText()).getBytes();
					send_packet=new DatagramPacket(send_message,send_message.length,inetaddress,port_num);// miao
					multicastsocket.send(send_packet);
					input_t.setText("");
				}catch(IOException e){
					System.out.println("error happen in the sender "+username);
				}
			}

			@Override
			public void mouseEntered(MouseEvent arg0) {
				// TODO Auto-generated method stub
				send_but.setBackground(new Color(255,128,0));
			}

			@Override
			public void mouseExited(MouseEvent arg0) {
				// TODO Auto-generated method stub
				send_but.setBackground(new Color(173,234,234));
			}

			@Override
			public void mousePressed(MouseEvent arg0) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void mouseReleased(MouseEvent arg0) {
				// TODO Auto-generated method stub
				
			}
    		
    	});
		//接收线程，程序监控群里是否有人发送消息，如果有，则取出，同时显示在消息框中
		Thread receive_thread=new Thread(){
			public void run(){
				byte receive_msg[]=new byte[1000];
				DatagramPacket receive_packet=new DatagramPacket(receive_msg,1000);
				while(true){
					try{
						multicastsocket.receive(receive_packet);
						byte[] receive_message=receive_packet.getData();
						text_area.setText(text_area.getText()+new String(receive_message,0,receive_packet.getLength())+"\n");
					}catch(Exception e){
						System.out.println("error happen in the receiver "+username);
					}
				}
			}
		};
		receive_thread.start();
	}
}
