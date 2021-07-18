package gui;	//UI即user interface,也即人机交互界面

import java.io.*;
import java.net.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Server {					
	public static void main(String args[]){
		new WindowServer();
	}
}
	
class WindowServer extends JFrame implements Runnable,ActionListener (){		
		JButton button1,button2;
		JTextField portArea;						
		JTextArea mainArea;					
		JTextField sendArea;						
					
		ServerSocket serversocket=null;
		Socket socket=null;
		DataInputStream in=null;
		DataOutputStream out=null;
		Thread thread;

		WindowServer() {
			super("服务器");					//子类ServerUI使用super调用父类的隐藏构造方法JFrame(String s)

			Container contain=getContentPane();			//新建容器并设置布局
			contain.setLayout(new BorderLayout());			
			
			JPanel portPanel=new JPanel();			//新建port上面板
			
			JLabel myLabel=new JLabel("Port:",LEFT);		//往上面板添加port:标签
			portPanel.add(mylabel);				

			portArea=new JTextField(30);				//往上面板添加port单行文本
			portPanel.add(portArea);

			button1 = new JButton("Start");			//往上面板添加start按钮
			portPanel.add(button1);
			
			JPanel sayPanel = new JPanel();			//新建sayPanel下面板并设置布局
			sayPanel.setLayout(new BorderLayout());		

			sayPanel.add(new JLabel("Say:"),BorderLayout.WEST);	//往下面板添加Say:标签
			
			sentArea=new JTextField(25);				//往下面板添加sendArea单行文本
			sayPanel.add(sendArea,BorderLayout.CENTER);
			
			JButton button2=new JButton("Say");			//往下面板添加Say按钮
			sayPanel.add(button2,BorderLayout.EAST)		
			
			mainArea=new JTextArea(10,30);			//新建主文本框
			
			contain.add(portPanel,BorderLayout.NORTH);		//往容器里添加上面板
			contain.add(mainArea,BorderLayout.CENTER);		//往容器里主文本框
			contain.add(panel,BorderLayout.SOUTH);		//往容器里添加下面板
			




		
			setSize(500,300);					//设置窗口大小
			setVisible(true);					//设置窗口为可见
			setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	//设置点击关闭图标，结束窗口所在应用程序
			pack();						//自动调整大小以适应其子组件大小与布局	
			button1.addActionListener(this);
			button2.setEnabled(true);		
			button2.addActionListener(this);
			button1.addActionListener(this);
        			button2.addActionListener(this);
			socket=new Socket();
			thread =new Thread(this);
	}x
}
public void actionPerformed(ActionEvent e) {         
        if(e.getSource()==button1) {
            mainArea.append("Server starting…\n");
            
            try {
                if(!socket.isConnected()) {
                ServerSocket serversocket=new ServerSocket(Integer.parseInt(portArea.getText()));
                socket=serversocket.accept();
                    mainArea.append("Client connected…\n");
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
            mainArea.append("服务器："+s_out+"\n");
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
                mainArea.append("客户端:"+s_in+"\n");
	 System.out.println();
            }
            catch(IOException e) {
                mainArea.setText("客户离开");
                socket=new Socket();
                break;
            }
        }
    }
}