package ChatRoom;

import java.awt.Color;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextArea;
public class friendDialogFrame {
	int port_num;
	String username;
	String friendname;
	InetAddress inetaddress;
	private DatagramSocket datagramsocket;
	JTextArea text_area;
	
    public friendDialogFrame(friend f,String user_name,JButton enter_but,DatagramSocket datagramsocket){
		friendname=f.friend_name;
		this.port_num=f.friend_port;
		username=user_name;
		this.datagramsocket=datagramsocket;
		inetaddress=f.friend_inetAddress;
		dialog_frame(enter_but);
	}
	void dialog_frame(JButton enter_but){
		//设置聊天窗口
		JFrame frame=new JFrame("与"+friendname+"的私聊页面");
		frame.setBounds(500,300,500,500);
		frame.setLayout(null);
		//设置聊天框标签
		JLabel label=new JLabel("");
		label.setBounds(0, 0, 520, 5);
		frame.add(label);
		//设置聊天框
		text_area=new JTextArea();
		text_area.setBounds(0, 0, 520, 280);
		frame.add(text_area);
		//设置输入标签
		JLabel input_l=new JLabel("  输入框");
		input_l.setBounds(0,295,510,15);//
		frame.add(input_l);
		//设置输入框
		JTextArea input_t=new JTextArea();
		input_t.setBounds(0, 320, 510, 103);//
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
		
		//好友私聊发送按钮
		send_but.addMouseListener(new MouseListener(){

			@Override
			//点击发送按钮时，将用户名以及输入框中的文本作为数据单播给好友，然后将输入框中的文本清空
			public void mouseClicked(MouseEvent arg0) {
				byte[] send_message;
				DatagramPacket send_packet;
				try{			
					send_message=(username+"@"+friendname+"@"+input_t.getText()).getBytes();
					send_packet=new DatagramPacket(send_message,send_message.length,inetaddress,port_num);
					datagramsocket.send(send_packet);
					text_area.setText(text_area.getText()+username+":"+input_t.getText()+"\n");
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
	}
}
