package gui;

import java.net.*;
import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Client {
	public static void main(String args[]) {
		new WindowClient();
	}
}

class WindowClient extends JFrame implements Runnable,ActionListener {
	JButton button1,button2;
	JTextField ipArea;
	JTextField portArea;
	JTextArea mainArea;
 	JTextField sendArea;

	Socket socket=null;					//
	DataInputStream in=null;
	DataOutputStream out=null;
	Thread thread;

	WindowClient() {
		super("客户端");
		
		Container contain = getContentPane();		//新建容器并设置布局
		contain.setLayout(new BorderLayout());

		JPanel ipportPanel = new JPanel();		//新建ipport上面板并设置布局
		
		ipportPanel.add(new JLabel("Server IP:"));	//往上面板添加Server IP:标签

		ipArea = new JTextField(15);			//往上面板添加ip单行文本
		ipArea.setText("127.0.0.1");
		ipportPanel.add(ipArea);

		ipportPanel.add(new JLabel("Server Port:"));	//往上面板添加Server Port:标签

		portArea =new JTextField(8);			//往上面板添加port单行文本
		ipportPanel.add(portArea);			

		button1 = new JButton("Connect");		//往上面板添加connect按钮
		ipportPanel.add(button1);			

		JPanel sayPanel = new JPanel();		//新建sayPanel下面板并设置布局
		sayPanel.setLayout(new BorderLayout());	

		sayPanel.add(new JLabel("Say:"),BorderLayout.WEST);//往下面板添加Say:标签

		sendArea = new JTextField(25);
		sayPanel.add(sendArea, BorderLayout.CENTER);	//往下面板添加sendArea单行文本

		JButton button2 = new JButton("Say");		//往下面板添加Say按钮
		sayPanel.add(button2, BorderLayout.EAST);
		
		mainArea = new JTextArea(10,30);		//新建主文本框

		contain.add(ipportPanel, BorderLayout.NORTH);	//往容器添加上面板
		contain.add(mainArea, BorderLayout.CENTER);	//往容器添加主文本框
		contain.add(sayPanel, BorderLayout.SOUTH);	//往容器添加下面板

		socket=new Socket();			//
		button1.setEnabled(false);			//？？？
        		button2.setEnabled(true);
		button1.addActionListener(this);
		button2.addActionListener(this);
		thread =new Thread(this);
		
		setSize(500, 300);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
public void actionPerformed(ActionEvent e) {          
        if(e.getSource()==button1) {
            
            try {
                if(!socket.isConnected()) {              //判断是否连接
                    show.append("Connect to server…\n");
                    InetAddress address=InetAddress.getByName(ipArea.getText());
                    InetSocketAddress socketAddress=new InetSocketAddress(address,Integer.parseInt(portArea.getText()));
                    socket.connect(socketAddress);
                    in=new DataInputStream(socket.getInputStream());
                    out=new DataOutputStream(socket.getOutputStream());
                    if(!thread.isAlive())
                        thread=new Thread(this);
                    thread.start();
                }
            }
            catch(IOException ee) {
                System.out.println(ee);
                socket=new Socket();
            }
        }
        if(e.getSource()==button2) {
            String s_out=sendArea.getText();
            mainArea.append("客户端："+s_out+"\n");
            try {
                out.writeUTF(s_out);			//将字符串以UTF格式写入输出流
            }
            catch(IOException e1) {}
        }
    }
    
    public void run() {
        String s_in=null;
        while(true) {
            try {
                s_in=in.readUTF();
                mainArea.append("服务器："+s_in+"\n");
                System.out.println();
            }
            catch(IOException e) {
                mainArea.setText("与服务器断开"+e);
                socket=new Socket();
                break;
            }
        }
    }
}