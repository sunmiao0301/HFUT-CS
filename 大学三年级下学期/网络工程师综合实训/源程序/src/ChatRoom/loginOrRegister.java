package ChatRoom;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class loginOrRegister{
	String username="";
	int userport;
	Socket socket=null;
	BufferedWriter out=null;
	volatile boolean login=false;
	public loginOrRegister(){
		login_reg();
	}
	void login_reg(){
		//登录面板 
		JFrame frame=new JFrame("登录注册页面");
		frame.setBounds(800,300,305,180);
		frame.setLayout(null);
		//设置用户名标签
		JLabel usr_name_l=new JLabel("用户名:");
		usr_name_l.setBounds(15, 0, 75, 50);
		frame.add(usr_name_l);
		//设置用户名文本
		JTextField usr_name_t=new JTextField();
		usr_name_t.setBounds(75, 10, 200, 30);
		frame.add(usr_name_t);
		//设置密码标签
		JLabel usr_pswd_l=new JLabel("密码#端口:");
		usr_pswd_l.setBounds(10, 46, 75, 50);
		frame.add(usr_pswd_l);
		//设置密码文本
		JTextField usr_pswd_t=new JTextField();
		usr_pswd_t.setBounds(75, 58, 200, 30);
		frame.add(usr_pswd_t);
		//登录按键
		JButton login_but=new JButton("登录");
		login_but.setBounds(15, 106, 100, 30);
		frame.add(login_but);
		//设置注册按键
		JButton register_but=new JButton("注册");
		register_but.setBounds(175, 106, 100, 30);
		frame.add(register_but);
		frame.setResizable(false);
		frame.setVisible(true);
		
		try{
			socket=new Socket("127.0.0.1",6666);
			out=new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
		}catch(Exception e){
			System.out.println("注册error");
		}
		//按下登陆按钮
		login_but.addMouseListener(new MouseAdapter(){
			public void mouseClicked(MouseEvent m){
				try{
					//将用户登陆输入的信息处理后送到服务器端
					String msg="login@"+usr_name_t.getText()+"@"+usr_pswd_t.getText()+"\n";
					out.write(msg);
					out.flush();
					//接收服务器端对消息处理后回传的信息
					BufferedReader in=new BufferedReader(new InputStreamReader(socket.getInputStream()));
					msg=in.readLine();
					String info[]=msg.split("@");
					if(info[0].equals("yes")){
						username=usr_name_t.getText();
						userport=Integer.valueOf(info[1]).intValue();
						out.close();
						in.close();
						frame.dispose();
						login=true;
					}else{
						usr_name_t.setText(info[2]);
					}
				}catch(Exception e){
					System.out.println(e);
				}
			}
			
		});
		//按下注册按钮
		register_but.addMouseListener(new MouseAdapter(){
			public void mouseClicked(MouseEvent m){
				try{//将用户注册输入的信息处理后送到服务器端
					String msg="register@"+usr_name_t.getText()+"@"+usr_pswd_t.getText()+"\n";
					out.write(msg);
					out.flush();
					//接收服务器端对消息处理后回传的信息
					BufferedReader in=new BufferedReader(new InputStreamReader(socket.getInputStream()));
					msg=in.readLine();
					String info[]=msg.split("@");
					if(info[0].equals("yes")){
						username=usr_name_t.getText();
						userport=Integer.valueOf(info[1]).intValue();
						out.close();
						in.close();
						frame.dispose();
						//建立新用户的数据库文件
						createFile(username);
						login=true;
					}else{
						usr_name_t.setText(info[2]);
					}
				}catch(Exception e){
					System.out.println(e);
				}
			}
		});
	}
	
	//新注册情况下，将自动建立文件//userdata//username//friends.txt&groups.txt
	void createFile(String username){
		//path表示你所创建文件的路径
		String path = ".//userdata//"+username;
		File f = new File(path);
		if(!f.exists()){
			f.mkdirs();
		} 
		String fileName="friends.txt";
		File file = new File(f,fileName);
		if(!file.exists()){
			try {
				file.createNewFile();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		fileName="groups.txt";//直接延用上面的filename，重新赋值即可
		file = new File(f,fileName);
		if(!file.exists()){
			try {
				file.createNewFile();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
