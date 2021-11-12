package Miao;

import java.sql.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Vector;

import javax.swing.JOptionPane;


public class DbProcess{
	Connection connection = null;
	public ResultSet rs = null;
	
	
	public Queue<String> list = new LinkedList<String>();
	public Queue<String> list_sum = new LinkedList<String>();
	
	//
	Connection con;// 连接数据库对象
  	Statement stmt;// 创建SQL命令对象
	//
	
	//Statement stmt;
	
	//mysql数据库url
	//String userMySql="root"; 
	//String passwordMySql="mzc277171";
	
    String JDriver = "com.microsoft.sqlserver.jdbc.SQLServerDriver";// SQL数据库引擎
    String connectDB = "jdbc:sqlserver://127.0.0.1:1433;DatabaseName=test";// 数据源 DatabaseName是已经创建的数据库的名字 不是表的名字
	
	
    //String userMySql = "com.microsoft.sqlserver.jdbc.SQLServerDriver";// SQL数据库引擎
    //String passwordMySql = "jdbc:sqlserver://127.0.0.1:1433;DatabaseName=test";// 数据源 DatabaseName是已经创建的数据库的名字 不是表的名字
	
	//String urlMySql = "jdbc:mysql://localhost:3306/education?user="+userMySql+"&password="+passwordMySql + "&useUnicode=true&characterEncoding=gbk";
	public DbProcess() {
		
	     try {
	         Class.forName(JDriver);// 加载数据库引擎，返回给定字符串名的类
	     } catch (ClassNotFoundException e) {
	          // e.printStackTrace();
	         System.out.println("加载数据库引擎失败");
	         System.exit(0);
	     }
	      
		
//		try {
//			//mysql数据库设置驱动程序类型
//			Class.forName("com.mysql.jdbc.Driver"); 
//			System.out.println("mysql数据库驱动加载成功");
//		}
//		catch(java.lang.ClassNotFoundException e) {
//			e.printStackTrace();
//		}
	}


	public void pro_queryAllProcess(){
				
		try {
			if(Login.identify.equals("adminView")) {
				
				String user = "adminView";
				String password = "123456";
				
	        	Connection con = DriverManager.getConnection(connectDB, user, password);// 连接数据库对象
	        	System.out.println("admin连接数据库成功,进入到DbProcess阶段");
	        	
	        	Statement stmt = con.createStatement();
	        	ResultSet sum = stmt.executeQuery("SELECT * FROM Project where proCK = '1'");
	        	
	        	while (sum.next()) {
		        	  list_sum.add(sum.getString("proCK"));
		        }
	        	
	        	
	        	ResultSet rs = stmt.executeQuery("SELECT * FROM Project");

	        	
	          while (rs.next()) {
	        	  list.add(rs.getString("proNo"));
	        	  list.add(rs.getString("proName"));
	        	  list.add(rs.getString("proCK"));
	        	  list.add(rs.getString("teaNo"));
	          }
	          System.out.println("全部查询——完成");
			}
			if(Login.identify.equals("孙淼")) {
				
				String user = "孙淼";
				String password = "123456";
				
	        	Connection con = DriverManager.getConnection(connectDB, user, password);// 连接数据库对象
	        	System.out.println("admin连接数据库成功,进入到DbProcess阶段");
	        	
	        	Statement stmt = con.createStatement();
	        	ResultSet rs = stmt.executeQuery("SELECT * FROM Project");
	        	
	          while (rs.next()) {
	        	  list.add(rs.getString("proNo"));
	        	  list.add(rs.getString("proName"));
	        	  list.add(rs.getString("proCK"));
	        	  list.add(rs.getString("teaNo"));
	          }
	          System.out.println("全部查询——完成");
			}
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}
	
	public void tea_queryAllProcess(){
		
		try {
			if(Login.identify.equals("adminView")) {
				
				String user = "adminView";
				String password = "123456";
				
	        	Connection con = DriverManager.getConnection(connectDB, user, password);// 连接数据库对象
	        	System.out.println("admin连接数据库成功,进入到DbProcess阶段");
	        	
	        	Statement stmt = con.createStatement();
	        	ResultSet rs = stmt.executeQuery("SELECT * FROM Teacher");
	        	
	          while (rs.next()) {
	        	  list.add(rs.getString("teaNo"));
	        	  list.add(rs.getString("teaName"));
	        	  list.add(rs.getString("teaDept"));
	        	  list.add(rs.getString("teaDuty"));
	        	  list.add(rs.getString("teaTitle"));
	        	  list.add(rs.getString("teaGender"));
	          }
	          System.out.println("全部查询——完成");
			}
			
			if(Login.identify.equals("孙淼")) {
				
				String user = "孙淼";
				String password = "123456";
				
	        	Connection con = DriverManager.getConnection(connectDB, user, password);// 连接数据库对象
	        	System.out.println("admin连接数据库成功,进入到DbProcess阶段");
	        	
	        	Statement stmt = con.createStatement();
	        	ResultSet rs = stmt.executeQuery("SELECT * FROM Teacher");
	        	
	          while (rs.next()) {
	        	  list.add(rs.getString("teaNo"));
	        	  list.add(rs.getString("teaName"));
	        	  list.add(rs.getString("teaDept"));
	        	  list.add(rs.getString("teaDuty"));
	        	  list.add(rs.getString("teaTitle"));
	        	  list.add(rs.getString("teaGender"));
	          }
	          System.out.println("全部查询——完成");
			}
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}
	
	public void disconnect(){
		try{
			if(connection != null){
				connection.close();
				connection = null;
			}
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}


//	public ResultSet executeQuery(String sql) {
//		try {
//			System.out.println("executeQuery(). sql = " + sql);
//			PreparedStatement pstm = connection.prepareStatement(sql);
//			// 执行查询
//			rs = pstm.executeQuery();
//		} 
//		catch(SQLException ex) { 
//			ex.printStackTrace();
//		}
//		return rs;
//	}
	
	//插入
	//executeUpdate 的返回值是一个整数，指示受影响的行数（即更新计数）。
	//executeUpdate用于执行 INSERT、UPDATE 或 DELETE 语句
	//以及 SQL DDL（数据定义语言）语句，例如 CREATE TABLE 和 DROP TABLE。
	
	//执行增、删、改语句的方法
//	public int executeUpdate(String sql) {
//		int count = 0;
//		connect();
//		try {
//			Statement stmt = connection.createStatement();
//			count = stmt.executeUpdate(sql);
//		} 
//		catch(SQLException ex) { 
//			System.err.println(ex.getMessage());		
//		}
//		disconnect();
//		return count;
//	}


public void pro_queryProcess()
{
	String singel_query = scoer.temp_proNo;
	
	try{
		if(Login.identify.equals("adminView")) {
		// 建立查询条件
		String sql = "select * from Project where proNo = ";
		
		sql = sql + "'" + singel_query + "'";

		String user = "adminView";
		String password = "123456";
		
    	Connection con = DriverManager.getConnection(connectDB, user, password);// 连接数据库对象
    	System.out.println("只根据项目号——查询完成");
    	
    	Statement stmt = con.createStatement();
		
		ResultSet rs = stmt.executeQuery(sql);
		
        while (rs.next()) {
      	  list.add(rs.getString("proNo"));
      	  list.add(rs.getString("proName"));
      	  list.add(rs.getString("proCK"));
      	  list.add(rs.getString("teaNo"));
        }
        System.out.println("读取完毕");       

		// 将查询获得的记录数据，转换成适合生成JTable的数据形式
		}
		else if(Login.identify.equals("孙淼")) {
		// 建立查询条件
		String sql = "select * from Project where proNo = ";
		
		sql = sql + "'" + singel_query + "'";

		String user = "孙淼";
		String password = "123456";
		
    	Connection con = DriverManager.getConnection(connectDB, user, password);// 连接数据库对象
    	System.out.println("只根据项目号——查询完成");
    	
    	Statement stmt = con.createStatement();
		
		ResultSet rs = stmt.executeQuery(sql);
		
        while (rs.next()) {
      	  list.add(rs.getString("proNo"));
      	  list.add(rs.getString("proName"));
      	  list.add(rs.getString("proCK"));
      	  list.add(rs.getString("teaNo"));
        }
        System.out.println("读取完毕");       

		// 将查询获得的记录数据，转换成适合生成JTable的数据形式
		}
		
	}catch(SQLException sqle){
		System.out.println("sqle = " + sqle);
		JOptionPane.showMessageDialog(null,
			"数据操作错误","错误",JOptionPane.ERROR_MESSAGE);
	}catch(Exception e){
		System.out.println("e = " + e);
		JOptionPane.showMessageDialog(null,
			"数据操作错误","错误",JOptionPane.ERROR_MESSAGE);
	}
}

public void tea_queryProcess()
{
	String singel_query = teacher_couse_aet.temp_teaNo;
	
	try{
		if(Login.identify.equals("adminView")) {
		// 建立查询条件
		String sql = "select * from Teacher where teaNo = ";
		
		sql = sql + "'" + singel_query + "'";

		String user = "adminView";
		String password = "123456";
		
    	Connection con = DriverManager.getConnection(connectDB, user, password);// 连接数据库对象
    	System.out.println("只根据项目号——查询完成");
    	
    	Statement stmt = con.createStatement();
		
		ResultSet rs = stmt.executeQuery(sql);
		
        while (rs.next()) {
      	  list.add(rs.getString("teaNo"));
      	  list.add(rs.getString("teaName"));
      	  list.add(rs.getString("teaDept"));
      	  list.add(rs.getString("teaDuty"));
      	list.add(rs.getString("teaTitle"));
      	list.add(rs.getString("teaGender"));
        }
        System.out.println("读取完毕");       

		// 将查询获得的记录数据，转换成适合生成JTable的数据形式
		}
		
		else if(Login.identify.equals("孙淼")) {
		// 建立查询条件
		String sql = "select * from Teacher where teaNo = ";
		
		sql = sql + "'" + singel_query + "'";

		String user = "孙淼";
		String password = "123456";
		
    	Connection con = DriverManager.getConnection(connectDB, user, password);// 连接数据库对象
    	System.out.println("只根据项目号——查询完成");
    	
    	Statement stmt = con.createStatement();
		
		ResultSet rs = stmt.executeQuery(sql);
		
        while (rs.next()) {
      	  list.add(rs.getString("teaNo"));
      	  list.add(rs.getString("teaName"));
      	  list.add(rs.getString("teaDept"));
      	  list.add(rs.getString("teaDuty"));
      	list.add(rs.getString("teaTitle"));
      	list.add(rs.getString("teaGender"));
        }
        System.out.println("读取完毕");       

		// 将查询获得的记录数据，转换成适合生成JTable的数据形式
		}
		
	}catch(SQLException sqle){
		System.out.println("sqle = " + sqle);
		JOptionPane.showMessageDialog(null,
			"数据操作错误","错误",JOptionPane.ERROR_MESSAGE);
	}catch(Exception e){
		System.out.println("e = " + e);
		JOptionPane.showMessageDialog(null,
			"数据操作错误","错误",JOptionPane.ERROR_MESSAGE);
	}
}

public void pro_updataProcess() {
	
	String single_proNo = scoer.temp_proNo;
	String single_proCK = scoer.temp_proCK;
	
	try{
		if(Login.identify.equals("adminView")) {
		
			String sql = "update Project set proCK = '";
			sql = sql + single_proCK + "'where proNo = '";
			sql = sql + single_proNo + "'";
			
		String user = "adminView";
		String password = "123456";
		
    	Connection con = DriverManager.getConnection(connectDB, user, password);// 连接数据库对象
    	
    	Statement stmt = con.createStatement();
		
   		int rs = stmt.executeUpdate(sql);
   		//System.out.println("");
   		
//   		while (rs > 0) {
//        	  list.add(rs.getString("proNo"));
//        	  list.add(rs.getString("proName"));
//        	  list.add(rs.getString("proCK"));
//        	  list.add(rs.getString("teaNo"));
//        	  rs--;
//          }
          System.out.println("项目验收完毕");
          
		// 将查询获得的记录数据，转换成适合生成JTable的数据形式
		}
		
	}catch(SQLException sqle){
		System.out.println("sqle = " + sqle);
		JOptionPane.showMessageDialog(null,
			"数据操作错误","错误",JOptionPane.ERROR_MESSAGE);
	}catch(Exception e){
		System.out.println("e = " + e);
		JOptionPane.showMessageDialog(null,
			"数据操作错误","错误",JOptionPane.ERROR_MESSAGE);
	}
	
}


public void pro_insertProcess() {
	
	String single_proNo = scoer.temp_proNo;
	String single_proName = scoer.temp_proName;
	String single_proCK = scoer.temp_proCK;
	String single_teaNo = scoer.temp_teaNo;
	
	try{
		if(Login.identify.equals("孙淼")) {
		
			String sql = "insert into Project (proNo, proName, proCK, teaNo) values ('";
			sql = sql + single_proNo + "', '";
			sql = sql + single_proName + "', '";
			sql = sql + "0" + "', '";
			sql = sql + single_teaNo + "');";
			
		String user = "孙淼";
		String password = "123456";
		
    	Connection con = DriverManager.getConnection(connectDB, user, password);// 连接数据库对象
    	
    	Statement stmt = con.createStatement();
		
   		int rs = stmt.executeUpdate(sql);
   		//System.out.println("");
   		
//   		while (rs > 0) {
//        	  list.add(rs.getString("proNo"));
//        	  list.add(rs.getString("proName"));
//        	  list.add(rs.getString("proCK"));
//        	  list.add(rs.getString("teaNo"));
//        	  rs--;
//          }
          System.out.println("项目验收完毕");
          
		// 将查询获得的记录数据，转换成适合生成JTable的数据形式
		}
		
	}catch(SQLException sqle){
		System.out.println("sqle = " + sqle);
		JOptionPane.showMessageDialog(null,
			"数据操作错误","错误",JOptionPane.ERROR_MESSAGE);
	}catch(Exception e){
		System.out.println("e = " + e);
		JOptionPane.showMessageDialog(null,
			"数据操作错误","错误",JOptionPane.ERROR_MESSAGE);
	}
}

}
