package Miao;

//科研管理系统登录页面

import javax.imageio.ImageIO;
import javax.swing.*;

import Miao.Manager;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

class Login extends JFrame implements ActionListener {
	
	// 定义组件
	//String stu_num="adminView";
	//String stu_pwd="123456";
	
	static String identify = "登陆者身份";
	
	JLabel jLuser = null;//用户
	JLabel jLpossword = null;//密码	
	JLabel jLloging=null;
	
	JTextField jTFuser = null;//姓名
	JTextField jTFpossword = null;//性别
	
	JButton logings = null;//登录
	JButton register = null;//登录
	public  void clear()
  {  
		jTFuser.setText("");
		jTFpossword.setText("");  
  }
	
	// 构造函数
	public Login() {
		// 创建组件	
		jLloging = new JLabel("高校科研管理系统");
		jLloging.setForeground(Color.blue);
		jLloging.setFont(new   java.awt.Font("Dialog",   0,   25));
		
		jLuser = new JLabel("用户:");
		jLpossword= new JLabel("密码:");
		jLuser.setFont(new   java.awt.Font("Dialog",   0,   19));
		jLpossword.setFont(new   java.awt.Font("Dialog",   0,   19));
		
		jTFuser = new JTextField(10);//用户名TextField
		jTFpossword = new JTextField(10);//密码TextField
		jTFuser.setFont(new   java.awt.Font("Dialog",   0,   19));
		jTFpossword.setFont(new   java.awt.Font("Dialog",   0,   19));
		
		logings = new JButton("登录");
		logings.setFont(new   java.awt.Font("Dialog",   1,   16));
		//register = new JButton("注册");
		//register.setFont(new   java.awt.Font("Dialog",   1,   16));

		JPanel jP1, jP2,jP3,jP4=null;
		JPanel jPTop, jPBottom = null;
		
		// 设置监听
		//logings.addActionListener();
		logings.addActionListener(this);

		jP1 = new JPanel();
		jP2 = new JPanel();
		jP3 = new JPanel();
		jP4 = new JPanel();
		
		jPTop = new JPanel();
		jPBottom = new JPanel();
		
		jP1.add(jLloging);
		
		jP2.add(jLuser);
		jP2.add(jTFuser);
		jP2.setLayout(new FlowLayout(FlowLayout.CENTER));
		jP2.setPreferredSize(new Dimension(20,20));
		
		jP3.add(jLpossword);
		jP3.add(jTFpossword);
		jP3.setLayout(new FlowLayout(FlowLayout.CENTER));
		jP3.setPreferredSize(new Dimension(20,20));
		
		jP4.add(logings);
		//jP4.add(register);
	
		jP4.setLayout(new FlowLayout(FlowLayout.CENTER));
		
		
		jPTop.setLayout(new GridLayout(4, 1));
		jPTop.add(jP1);
		jPTop.add(jP2);
		jPTop.add(jP3);
		jPTop.add(jP4);
		
		this.add("North",jP1);
		this.add("Center",jP2);
		this.add("Center",jP3);
		this.add("Center",jP4);
		
		/*
		BufferedImage img=null;
		try {
			img=ImageIO.read(new File("./img/bg.gif"));
		}catch (IOException e) {
			e.printStackTrace();
		}
		JLabel labl=new JLabel(new ImageIcon(img));
		getContentPane().add(labl);
		labl.setBounds(0, 0, img.getWidth(), img.getHeight());
      */
		this.setLayout(new GridLayout(4, 1));
		this.setTitle("高校科研管理系统登录");
		this.setSize(370,270);
		this.setLocation(555, 225);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
		this.setResizable(false);
		
		//dbProcess = new DbProcess();
	}
	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		//if(stu_num.equals(jTFuser.getText())&&stu_pwd.equals(jTFpossword.getText()))  
		
		String user = jTFuser.getText();
		String password = jTFpossword.getText();
		
	    String JDriver = "com.microsoft.sqlserver.jdbc.SQLServerDriver";// SQL数据库引擎
	    String connectDB = "jdbc:sqlserver://127.0.0.1:1433;DatabaseName=test";// 数据源 DatabaseName是已经创建的数据库的名字 不是表的名字
		
		//if((jTFuser.getText()).equals(admin_num) && (jTFpossword.getText()).equals(admin_pwd))
		        //{  
//          		if(user.equals("adminView") && password.equals("123456")) {
//							Connection con = DriverManager.getConnection(connectDB, user, password);
//          				System.out.println("admin连接数据库成功");
//          				
//          				
//          				Statement stmt = con.createStatement();// 创建SQL命令对象
//          	          
//          	          // 创建表
//          	          System.out.println("开始创建表");
//          	          String query = "create table TABLE1(ID NCHAR(2),NAME NCHAR(10))";// 创建表SQL语句
//          	          stmt.executeUpdate(query);// 执行SQL命令对象
//          	          System.out.println("表创建成功");
//          				//创建新界面  
//          				//new Manager();
//          				//this.setVisible(false);
//		            
//		        }
//	    		try {
	    		//确定登录的是admin还是教师
	    			if(jTFuser.getText().equals("adminView") && jTFpossword.getText().equals("123456")) {
	    				identify = "adminView";
	    	        	//Connection con = DriverManager.getConnection(connectDB, user, password);// 连接数据库对象
	    	        	System.out.println("admin连接数据库成功");
						new Manager();
						this.setVisible(false);
						System.out.println("成功进入");
	    	          	//Statement stmt = con.createStatement();// 创建SQL命令对象
	    	          	
	    			}
	    			else if(jTFuser.getText().equals("孙淼") && jTFpossword.getText().equals("123456")) {
	    				identify = "孙淼";
	    	        	//Connection con = DriverManager.getConnection(connectDB, user, password);// 连接数据库对象
	    	        	System.out.println("孙淼连接数据库成功");
						new Manager();
						this.setVisible(false);
						System.out.println("成功进入");
	    	          	//Statement stmt = con.createStatement();// 创建SQL命令对象
	    	          	
	    			}
	          		else if(jTFuser.getText().isEmpty()&&jTFpossword.getText().isEmpty())
			        {  
			            JOptionPane.showMessageDialog(null,"请输入用户名和密码！","提示消息",JOptionPane.WARNING_MESSAGE);  
			        }else if(jTFuser.getText().isEmpty())  
			        {  
			            JOptionPane.showMessageDialog(null,"请输入用户名！","提示消息",JOptionPane.WARNING_MESSAGE);  
			        }else if(jTFuser.getText().isEmpty())  
			        {  
			            JOptionPane.showMessageDialog(null,"请输入密码！","提示消息",JOptionPane.WARNING_MESSAGE);  
			        }else  
			        {  
			            JOptionPane.showMessageDialog(null,"用户名或者密码错误！\n请重新输入","提示消息",JOptionPane.ERROR_MESSAGE);  
			            //清空输入框  
			            clear();  
			        } 
	    			
//	    		}
//	    		catch (SQLException e) {
//	              e.printStackTrace();
//	              System.out.println("数据库连接错误");
//	              System.exit(0);
//	    		}
	}
}