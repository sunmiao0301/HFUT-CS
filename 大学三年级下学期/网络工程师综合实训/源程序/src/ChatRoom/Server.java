package ChatRoom;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.*;
import java.net.*;
import java.util.HashMap;

import javax.swing.JButton;
import javax.swing.JFrame;
public class Server {
	int port=6666;
	ServerSocket server_socket=null;
	//用于保存用户名和密码;
	HashMap<String,String> user=null;
	boolean Is_login=false;
	public void run(){
		try{
			server_socket=new ServerSocket(port);
			user=new HashMap<String,String>();
			JFrame frame=new JFrame();
			
			frame.setVisible(true);
			frame.setSize(150, 200);
			frame.setLayout(null);
			JButton but=new JButton("退出");
			but.setBounds(0,0,160,160);
			frame.add(but);	
			frame.setResizable(false);
			but.addMouseListener(new MouseAdapter(){
				public void mouseClicked(MouseEvent m){
					System.exit(0);
				}	
			});
			while(true){
				Client client=new Client(server_socket.accept());
				client.start();
			}				
		}catch(Exception e){
			System.out.println(e);
		}
	}
	
	class Client extends Thread{
		Socket socket=null;
		Client(Socket socket){
			this.socket=socket;
		}
		public void run(){
			try{
				BufferedReader in=new BufferedReader(new InputStreamReader(socket.getInputStream()));
				BufferedWriter out=new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
				String login_reg;
				while(true){
					login_reg=in.readLine();
					//登陆/注册模块传来的信息以@分段
					String info[]=login_reg.split("@");
					//分段结果大于三段
					if(info.length>3){
						out.write("no@no@用户名或密码非法\n");
						out.flush();
					//分段结果小于三段
					}else if(info.length<3){
						out.write("no@no@请输入完整信息\n");
						out.flush();
					//分段结果等于三段
					}else{
						//具体是注册模块时
						if(info[0].equals("register")){
							//老用户注册
							if(user.containsKey(info[1])){
								out.write("no@register@用户已存在\n");
								out.flush();
							//新用户第一次注册
							}else{
								String port[]=info[2].split("#");
								out.write("yes@"+port[1]+"@欢迎\n");
								out.flush();
								user.put(info[1],info[2]);	
							}
						//具体是登陆模块时
						}else if(info[0].equals("login")){
							//老用户登陆
							if(user.containsKey(info[1])){
								if(user.get(info[1]).equals(info[2])){
									String port[]=info[2].split("#");
									out.write("yes@"+port[1]+"@欢迎\n");
									out.flush();
							//老用户密码错误时
								}else{
									out.write("no@login@密码错误\n");
									out.flush();
									System.out.println("注册成功4");
								}
							//不允许新用户直接登录
							}else{
								out.write("no@login@用户名不存在请注册\n");
								out.flush();
							}
						}
					}
				}
			}catch(Exception e){
				System.out.println(e);
			}
		}
	}
	
	public void info(){
		System.out.println("服务器已开启");
	}
	public static void main(String args[]){
		Server server=new Server();
		server.info();
		server.run();
		
	}
}

