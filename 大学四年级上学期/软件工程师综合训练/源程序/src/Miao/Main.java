package Miao;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.sql.*;

public class Main {

public ResultSet rs;//test
	
public static void main(String[] args) {
	
      String JDriver = "com.microsoft.sqlserver.jdbc.SQLServerDriver";// SQL数据库引擎
      String connectDB = "jdbc:sqlserver://127.0.0.1:1433;DatabaseName=test";// 数据源 DatabaseName是已经创建的数据库的名字 不是表的名字
      
      try {
          Class.forName(JDriver);// 加载数据库引擎，返回给定字符串名的类
      } catch (ClassNotFoundException e) {
          // e.printStackTrace();
          System.out.println("加载数据库引擎失败");
          System.exit(0);
      }
      
      System.out.println("数据库驱动成功");
      
      Login login = new Login();
      
  }
}