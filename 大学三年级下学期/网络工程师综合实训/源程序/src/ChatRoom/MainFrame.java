package ChatRoom;

import java.awt.Color;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.util.ArrayList;
import java.util.HashMap;

import javax.swing.*;

public class MainFrame {
	int userport;
	String username;
	JFrame frame;
	JPanel panel;
	JPanel add_panel;
	JButton friend_but;
	JButton group_but;
	JButton new_friend_but;
	JButton new_group_but;
	JScrollPane scroll;
	int num=0;
	volatile HashMap<String,friendDialogFrame> open_dialog;
	DatagramSocket datagramsocket;
	MainFrame(Member member){
		username=member.username;
		userport=member.userport;
		open_dialog=new HashMap<String,friendDialogFrame>();
		
		try{
			datagramsocket=new DatagramSocket(userport);
		}catch(Exception e){
			System.out.println(e);
		}
		//设置frame
		frame=new JFrame("用户"+username+"主界面");
		frame.setLayout(null);
		frame.setBounds(100, 200, 500, 500);
		//设置panel
		panel=new JPanel();
		panel.setLayout(null);
		panel.setBounds(0, 0, 500, 40);
		//设置好友按钮
		friend_but=new JButton("好友列表");
		friend_but.setBounds(0, 1, 125, 40);
		panel.add(friend_but);
		//设置好友按钮
		group_but=new JButton("群聊列表");
		group_but.setBounds(125, 1, 125, 40);
		panel.add(group_but);
		//设置好友按钮
		new_friend_but=new JButton("添加好友");
		new_friend_but.setBounds(250, 1, 125, 40);
		panel.add(new_friend_but);
		//设置好友按钮
		new_group_but=new JButton("加入群聊");
		new_group_but.setBounds(375, 1, 124, 40);
		panel.add(new_group_but);
		frame.add(panel);
		//设置add_panel
		add_panel=new JPanel();
		add_panel.setLayout(null);
		scroll=new JScrollPane(add_panel);
		scroll.setBounds(0, 40, 500, 760);
		scroll.setBackground(new Color(0,0,0));
		frame.add(scroll);
		//init_panel_g(member.group_array);
		init_panel_f(member.friend_array);	
		frame.setVisible(true);
		frame.setResizable(false);
		
		//好友按钮
		friend_but.addMouseListener(new MouseListener(){
			@Override
			public void mouseClicked(MouseEvent arg0) {
				num=0;
				add_panel.removeAll();
				init_panel_f(member.friend_array);
				add_panel.repaint();
			}

			@Override
			public void mouseEntered(MouseEvent arg0) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void mouseExited(MouseEvent arg0) {
				// TODO Auto-generated method stub
				
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
		
		//群聊按钮
		group_but.addMouseListener(new MouseListener(){

			@Override
			public void mouseClicked(MouseEvent e) {
				num=0;
				add_panel.removeAll();
				init_panel_g(member.group_array);
				//frame.revalidate(); 
				add_panel.repaint();
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
		//添加好友按钮
	    new_friend_but.addMouseListener(new MouseAdapter(){
			public void mouseClicked(MouseEvent m){
				new addFriend(member);
			}
		});
	    //添加群组按钮
	    new_group_but.addMouseListener(new MouseAdapter(){
	    	public void mouseClicked(MouseEvent m){
	    		new addGroup(member);
			}
	    });
	    byte receive_pak[]=new byte[1000];
		DatagramPacket receive_packet=new DatagramPacket(receive_pak,1000);
	    while(true){
	    	try{	
	    		
	    		//读出消息
				datagramsocket.receive(receive_packet);
				byte[] receive_message=receive_packet.getData();
				String rece_msg=new String(receive_message,0,receive_packet.getLength());
				deal_msg(rece_msg);
				
			}catch(Exception e){
				System.out.println("error happen in the receiver "+username+e);
			}
	    }
	
	}
	synchronized void deal_msg(String rece_msg){
		String msg[]=rece_msg.split("@");
		System.out.println(msg[2]);
		if(open_dialog.containsKey(msg[0])){
			open_dialog.get(msg[0]).text_area.setText(open_dialog.get(msg[0]).text_area.getText()+msg[0]+":"+msg[2]+"\n");
			System.out.println(msg[2]);
		}else{
			System.out.println("?????");
		}
	}
	/*
	 * 用好友信息来初始化add_panel
	 */
	void init_panel_f(ArrayList<friend> f_r){
		for(friend f : f_r){
			draw_panel(f);
		}
		
	}
	/*
	 * 用群组信息来初始化add_panel
	 */
	void init_panel_g(ArrayList<group> g_r){
		for(group g : g_r){
			draw_panel(g);
		}
	}
	
	//根据一个好友的信息，在panel上显示出一个好友控件
	void draw_panel(friend f){
		//好友的IP地址
		JLabel address=new JLabel("             好友IP地址:"+f.friend_inetAddress);
		address.setBounds(0, 40*num, 200, 40);
		address.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
		add_panel.add(address);
		//好友的端口号
		JLabel name=new JLabel("            好友用户名:"+f.friend_name);
		name.setBounds(200, 40*num, 175, 40);
		name.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
		add_panel.add(name);
		//与好友聊天按键
		JButton enter_but=new JButton("开始私聊");
		enter_but.setBounds(375, 40*num, 124, 40);
		add_panel.add(enter_but);
		num++;
		add_panel.revalidate(); 
		enter_but.addMouseListener(new MouseAdapter(){
			public void mouseClicked(MouseEvent m){
				open_dialog.put(f.friend_name, new friendDialogFrame(f,username,enter_but,datagramsocket));
				//enter_but.setEnabled(false);
			}
		});
	}
	//根据一个群组的信息，在panel上显示处一个群组控件
	void draw_panel(group g){
		//好友的IP地址
		JLabel address=new JLabel("             群聊IP地址"+g.group_inetAddress);
		address.setBounds(0, 40*num, 200, 40);
		address.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
		add_panel.add(address);
		//好友的端口号
		JLabel name=new JLabel("            群聊组名称:"+g.group_name);
		name.setBounds(200, 40*num, 175, 40);
		name.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
		add_panel.add(name);
		//与好友聊天按键
		JButton enter_but=new JButton("进入群聊");
		enter_but.setBounds(375, 40*num, 125, 40);
		add_panel.add(enter_but);
		num++;
		add_panel.revalidate();
		enter_but.addMouseListener(new MouseAdapter(){
			public void mouseClicked(MouseEvent m){
				if(enter_but.isEnabled()){
					new groupDialogFrame(g,username,enter_but);
					//enter_but.setEnabled(false);
				}
			}
		});
	}
	

}
