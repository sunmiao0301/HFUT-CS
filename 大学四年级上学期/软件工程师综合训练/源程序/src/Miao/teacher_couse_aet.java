package Miao;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Vector;

public class teacher_couse_aet extends Panel implements ActionListener {
	// 定义组件
	JLabel jLStudentInfoTable = null;//学生信息表
	JLabel jLSelectQueryField = null;//选择查询字段
	//JLabel jLEqual = null;//=
	JLabel jLteacher = null;//学号
	JLabel jLScourse = null;//姓名
	JLabel jLjidian = null;//班级
	JLabel jLclassroom = null;//班级
	JLabel jLwe_day = null;//班级
	JLabel jLclasnumer = null;//班级

	JTextField jTteacher = null;//查询字段
	JTextField jTScourse = null;//学号
	JTextField jTjidian = null;//姓名
	JTextField jTclassroom = null;//班级
	JTextField jTwe_day = null;//班级
	JTextField jTclasnumer = null;//班级
	JTextField jTFQueryField=null;
	
	//定义界面上的button
	JButton jBQuery = null;//查询
	JButton jBQueryAll = null;//查询所有记录
	JButton jBInsert = null;//插入
	JButton jBUpdate = null;//更新
	JButton jBDeleteCurrentRecord = null;//删除当前记录
	//JButton jBDeleteAllRecords = null;//删除所有记录
	
	//JComboBox jCBSelectQueryField = null;
	//下拉框
	JComboBox<String> jCBSelectQueryField = null;//查询字段
	JPanel jP1, jP2,jP3,jP4,jP5,jP6 = null;
	JPanel jPTop, jPBottom = null;
	DefaultTableModel studentTableModel = null;
	JTable studentJTable = null;
	JScrollPane studentJScrollPane = null;
	Vector studentVector = null;
	Vector titleVector = null;
	
	private static DbProcess dbProcess;
	String SelectQueryFieldStr = "学号";
	
	// 构造函数
	public teacher_couse_aet() {
		// 创建组件	
		jLStudentInfoTable = new JLabel("教师信息");
		jLSelectQueryField = new JLabel("请通过教师号查询");
		//jLEqual = new JLabel(" = ");
		jLteacher = new JLabel("教师号");
		jLScourse = new JLabel("教师名");
		jLjidian = new JLabel("部门");
		jLclassroom = new JLabel("职务");
		jLwe_day = new JLabel("职称");
		jLclasnumer = new JLabel("性别");
		
		
		jTteacher = new JTextField(10);//查询字段
		jTScourse = new JTextField(10);//学号
		jTjidian = new JTextField(10);//姓名
		jTclassroom = new JTextField(10);//性别
		jTwe_day = new JTextField(10);//性别
		jTclasnumer = new JTextField(10);//性别
		jTFQueryField=new JTextField(10);
		
		jBQuery = new JButton("查询");
		jBQueryAll = new JButton("查询所有记录");
		jBInsert = new JButton("插入");
		jBUpdate = new JButton("更新");
		jBDeleteCurrentRecord = new JButton("删除当前记录");
		//jBDeleteAllRecords = new JButton("删除所有记录");
		// 设置监听
		jBQuery.addActionListener(this);
		jBQueryAll.addActionListener(this);
		jBInsert.addActionListener(this);
		jBUpdate.addActionListener(this);
		jBDeleteCurrentRecord.addActionListener(this);
		//jBDeleteAllRecords.addActionListener(this);
		
		jCBSelectQueryField = new JComboBox<String>();//查询字段
		jCBSelectQueryField.addItem("教师号");
		jCBSelectQueryField.addItem("教师名");
		jCBSelectQueryField.addItem("部门");
		jCBSelectQueryField.addItem("职务");
		jCBSelectQueryField.addItem("职称");
		jCBSelectQueryField.addItem("性别");
//		jCBSelectQueryField.addItemListener(new ItemListener() {//下拉框事件监听  
//            public void itemStateChanged(ItemEvent event) {  
//                switch (event.getStateChange()) {  
//                case ItemEvent.SELECTED:  
//                	SelectQueryFieldStr = (String) event.getItem();  
//                    System.out.println("选中：" + SelectQueryFieldStr);  
//                    break;  
//                case ItemEvent.DESELECTED:  
//                    System.out.println("取消选中：" + event.getItem());  
//                    break;  
//                }  
//            }  
//        });
	
		studentVector = new Vector();
		titleVector = new Vector();
		
		// 定义表头
		titleVector.add("教师号");
		titleVector.add("教师名");
		titleVector.add("部门");
		titleVector.add("职务");
		titleVector.add("职称");
		titleVector.add("性别");
		//studentTableModel = new DefaultTableModel(tableTitle, 15);
		studentJTable = new JTable(studentVector, titleVector);
		studentJTable.setPreferredScrollableViewportSize(new Dimension(600,200));
		studentJScrollPane = new JScrollPane(studentJTable);
		//分别设置水平和垂直滚动条自动出现
		studentJScrollPane.setHorizontalScrollBarPolicy(                
                JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
		studentJScrollPane.setVerticalScrollBarPolicy(                
                JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
		
		//为表格添加监听器 
		studentJTable.addMouseListener(new MouseAdapter()
		{ 
			public void mouseClicked(MouseEvent e) 
			{ 
				int row = ((JTable) e.getSource()).rowAtPoint(e.getPoint()); // 获得行位置
				System.out.println("mouseClicked(). row = " + row);
				Vector v = new Vector();
				v = (Vector) studentVector.get(row);

				jTteacher.setText((String) v.get(0));// 学号
				jTScourse.setText((String) v.get(1));
				jTjidian.setText((String) v.get(2));// 姓名
				jTclassroom.setText((String) v.get(3));// 班级
				jTwe_day.setText((String) v.get(4));
				jTclasnumer.setText((String) v.get(5));
				
			}
		});


		jP1 = new JPanel();
		jP2 = new JPanel();
		jP5 = new JPanel();
		jP3 = new JPanel();
		jP4 = new JPanel();
		jP5 = new JPanel();
		jP6 = new JPanel();
		
		jPTop = new JPanel();
		jPBottom = new JPanel();
		
		jP1.add(jLStudentInfoTable,BorderLayout.SOUTH);
		jP2.add(studentJScrollPane);
		
		
		jP3.add(jLSelectQueryField);    //选择查询字段
		jP3.add(jCBSelectQueryField);   //查询字段
		//jP3.add(jLEqual);  //=
		jP3.add(jTFQueryField);	
		jP3.add(jBQuery);
		jP3.add(jBQueryAll);
		jP3.setLayout(new FlowLayout(FlowLayout.CENTER));
		jP3.setPreferredSize(new Dimension(20,20));
		
		jP4.add(jLteacher);
		jP4.add(jTteacher);
		jP4.add(jLScourse);
		jP4.add(jTScourse);
		jP4.add(jLjidian);
		jP4.add(jTjidian);
		jP4.setLayout(new FlowLayout(FlowLayout.CENTER));
		jP4.setPreferredSize(new Dimension(30,30));
		jP5.add(jLclassroom);
		jP5.add(jTclassroom);
		jP5.add(jLwe_day);
		jP5.add(jTwe_day);
		jP5.add(jLclasnumer);
		jP5.add(jTclasnumer);
		jP5.setLayout(new FlowLayout(FlowLayout.CENTER));
		jP5.setPreferredSize(new Dimension(20,20));
		
		
		jP6.add(jBInsert);
		jP6.add(jBUpdate);
		jP6.add(jBDeleteCurrentRecord);
		//jP6.add(jBDeleteAllRecords);
		jP6.setLayout(new FlowLayout(FlowLayout.CENTER));
		jP6.setPreferredSize(new Dimension(20,20));
		
		jPTop.add(jP1);
		jPTop.add(jP2);
		
		jPBottom.setLayout(new GridLayout(4, 1));
		jPBottom.add(jP3);
		jPBottom.add(jP4);
		jPBottom.add(jP5);
		jPBottom.add(jP6);
		this.add("North", jPTop);
		this.add("South", jPBottom);
		
	
		
		this.setLayout(new GridLayout(2, 1));
		//this.setTitle("教室课程设置表");
		this.setSize(580, 500);
		this.setLocation(150, 150);
		//this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
		//this.setResizable(false);
		
		
		dbProcess = new DbProcess();
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getActionCommand().equals("查询")  
				&& !jTFQueryField.getText().isEmpty()){
				System.out.println("actionPerformed().查询");
				String sQueryField = jTFQueryField.getText().trim();
				queryProcess(sQueryField);
				jTFQueryField.setText("");
			}else if(e.getActionCommand().equals("查询所有记录")) {
				System.out.println("actionPerformed(). 查询所有记录");
				queryAllProcess();
			}
//			else if(e.getActionCommand().equals("插入")
//					&& !jTteacher.getText().isEmpty()
//					&& !jTScourse.getText().isEmpty()
//					&& !jTjidian.getText().isEmpty()
//					&& !jTclassroom.getText().isEmpty()
//					&& !jTwe_day.getText().isEmpty()
//					&& !jTclasnumer.getText().isEmpty()){
//				System.out.println("actionPerformed(). 插入");
//				insertProcess();
//			}
		}
	
	
	/*
	public static void main(String[] args) {
		teacher_couse_aet getcon = new  teacher_couse_aet();
   }
   */
	public static String temp_teaNo;
	
	public void queryProcess(String jTFQueryField)
	{
		
		temp_teaNo = jTFQueryField;
		
		dbProcess.tea_queryProcess();
		
		studentVector.clear();
		
        while (!dbProcess.list.isEmpty()) {
            
      	  //System.out.print(dbProcess.list.poll());
      	  	Vector v = new Vector();
				v.add(dbProcess.list.poll());
				v.add(dbProcess.list.poll());
				v.add(dbProcess.list.poll());
				v.add(dbProcess.list.poll());
				v.add(dbProcess.list.poll());
				v.add(dbProcess.list.poll());
				studentVector.add(v);
        }
        
			studentJTable.updateUI();
			dbProcess.disconnect();
	}
	
	public void queryAllProcess()
	{
		dbProcess.tea_queryAllProcess();	
		
		studentVector.clear();
		  
        while (!dbProcess.list.isEmpty()) {
    
      	  	Vector v = new Vector();
				v.add(dbProcess.list.poll());
				v.add(dbProcess.list.poll());
				v.add(dbProcess.list.poll());
				v.add(dbProcess.list.poll());
				v.add(dbProcess.list.poll());
				v.add(dbProcess.list.poll());
				studentVector.add(v);
        }
        
        studentJTable.updateUI();
        		
        System.out.println("读取完毕");
        
			dbProcess.disconnect();	
	}
	
	public String jCBSelectQueryFieldTransfer(String InputStr)
	{
		String outputStr = "";
		System.out.println("jCBSelectQueryFieldTransfer(). InputStr = " + InputStr);
		
		if(InputStr.equals("教师")){
			outputStr = "教师";
		}else if(InputStr.equals("课程名")){
			outputStr = "课程名";
		}else if(InputStr.equals("学分绩点")){
			outputStr = "学分绩点";
		}
		else if(InputStr.equals("上课教室")){
			outputStr = "上课教室";
		}
		else if(InputStr.equals("上课周次")){
			outputStr = "上课周次";
		}
		else if(InputStr.equals("节次")){
			outputStr = "节次";
		}
		System.out.println("jCBSelectQueryFieldTransfer(). outputStr = " + outputStr);
		return outputStr;
	}
}
