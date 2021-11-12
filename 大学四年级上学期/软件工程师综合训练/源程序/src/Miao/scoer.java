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
import java.sql.Statement;
import java.util.Vector;

public class scoer extends Panel implements ActionListener {
	// 定义组件
	JLabel jLStudentInfoTable = null;//学生信息表
	JLabel jLSelectQueryField = null;//选择查询字段
	JLabel jLEqual = null;//=
	JLabel jLSNo = null;//学号
	JLabel jLSName = null;//姓名
	JLabel jLcourse = null;//课程号
	JLabel jLscoer = null;//成绩
	
	JTextField jTFQueryField = null;//查询字段
	JTextField jTFSNo = null;//学号
	JTextField jTFSName = null;//姓名
	JTextField jTFcourse = null;//课程号
	JTextField jTFscoer = null;//成绩
	
	//定义界面上的button
	JButton jBQuery = null;//查询
	JButton jBQueryAll = null;//查询所有记录
	JButton jBInsert = null;//插入
	JButton jBUpdate = null;//更新
	JButton jBDeleteCurrentRecord = null;//删除当前记录
	JButton jBDeleteAllRecords = null;//删除所有记录
	
	//JComboBox jCBSelectQueryField = null;
	//下拉框
	JComboBox<String> jCBSelectQueryField = null;//查询字段
	JPanel jP1, jP2,jP3,jP4,jP5 = null;
	JPanel jPTop, jPBottom = null;
	DefaultTableModel studentTableModel = null;
	JTable studentJTable = null;
	JScrollPane studentJScrollPane = null;
	Vector studentVector = null;
	Vector titleVector = null;
	
	private static DbProcess dbProcess;
	
	String SelectQueryFieldStr = "项目号";
	
	// 构造函数
	public scoer() {
		// 创建组件	
		jLStudentInfoTable = new JLabel("科研项目信息");
		jLSelectQueryField = new JLabel("请通过项目号查找");
		jLEqual = new JLabel(" = ");
		jLSNo = new JLabel("项目号");
		jLSName = new JLabel("项目名");
	    jLcourse = new JLabel("验收情况");//课程号
		jLscoer = new JLabel("教师号");;//成绩
		
		jTFQueryField = new JTextField(10);//查询字段
		jTFSNo = new JTextField(18);//学号
		jTFSName = new JTextField(18);//姓名
		jTFcourse = new JTextField(18);//课程号
	    jTFscoer = new JTextField(18);//成绩
		
		jBQuery = new JButton("查询");
		jBQueryAll = new JButton("查询所有记录");
		jBInsert = new JButton("插入");
		jBUpdate = new JButton("更新");
		jBDeleteCurrentRecord = new JButton("删除当前记录");
		jBDeleteAllRecords = new JButton("删除所有记录");
		// 设置监听
		jBQuery.addActionListener(this);
		jBQueryAll.addActionListener(this);
		jBInsert.addActionListener(this);
		jBUpdate.addActionListener(this);
		jBDeleteCurrentRecord.addActionListener(this);
		jBDeleteAllRecords.addActionListener(this);
		
		jCBSelectQueryField = new JComboBox<String>();//查询字段
		jCBSelectQueryField.addItem("项目号");  
		jCBSelectQueryField.addItem("项目名");  
		jCBSelectQueryField.addItem("验收情况");
		jCBSelectQueryField.addItem("教师号");
		
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
		titleVector.add("项目号");
		titleVector.add("项目名");
		titleVector.add("验收情况");
		titleVector.add("教师号");
		//studentTableModel = new DefaultTableModel(tableTitle, 15);
		studentJTable = new JTable(studentVector, titleVector);
		studentJTable.setPreferredScrollableViewportSize(new Dimension(600,260));
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

				jTFSNo.setText((String) v.get(0));// 学号
				jTFSName.setText((String) v.get(1));// 姓名
				jTFcourse.setText((String) v.get(2));// 课程号
				jTFscoer.setText((String) v.get(4));// 成绩号
			}
		});


		jP1 = new JPanel();
		jP2 = new JPanel();
		jP5 = new JPanel();
		jP3 = new JPanel();
		jP4 = new JPanel();
		jPTop = new JPanel();
		jPBottom = new JPanel();
		
		jP1.add(jLStudentInfoTable,BorderLayout.SOUTH);
		jP2.add(studentJScrollPane);
		
		
		jP3.add(jLSelectQueryField);    //选择查询字段
		//jP3.add(jCBSelectQueryField);   //查询字段
		//jP3.add(jLEqual);  //=
		jP3.add(jTFQueryField);	
		jP3.add(jBQuery);
		jP3.add(jBQueryAll);
		jP3.setLayout(new FlowLayout(FlowLayout.CENTER));
		jP3.setPreferredSize(new Dimension(20,20));
		
		jP4.add(jLSNo);
		jP4.add(jTFSNo);
		jP4.add(jLSName);
		jP4.add(jTFSName);
		jP4.add(jLcourse);
		jP4.add(jTFcourse);
		jP4.add(jLscoer);
		jP4.add(jTFscoer);
		
		jP4.setLayout(new FlowLayout(FlowLayout.CENTER));
		jP4.setPreferredSize(new Dimension(30,30));
		
		
		jP5.add(jBInsert);
		jP5.add(jBUpdate);
		jP5.add(jBDeleteCurrentRecord);
		jP5.add(jBDeleteAllRecords);
		jP5.setLayout(new FlowLayout(FlowLayout.CENTER));
		jP5.setPreferredSize(new Dimension(20,20));
		
		jPTop.add(jP1);
		jPTop.add(jP2);
		
		jPBottom.setLayout(new GridLayout(3, 1));
		jPBottom.add(jP3);
		jPBottom.add(jP4);
		jPBottom.add(jP5);
		this.add("North", jPTop);
		this.add("South", jPBottom);
	
		this.setLayout(new GridLayout(2, 1));
		//this.setTitle("成绩信息操作");
		this.setSize(530, 500);
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
				System.out.println("actionPerformed(). 查询");
				String sQueryField = jTFQueryField.getText().trim();
				queryProcess(sQueryField);
				jTFQueryField.setText("");
			}
		
		else if(e.getActionCommand().equals("查询所有记录")) {
				System.out.println("actionPerformed(). 查询所有记录");
				queryAllProcess();
			}
		
		else if(e.getActionCommand().equals("插入")
					&& !jTFSNo.getText().isEmpty()
					&& !jTFSName.getText().isEmpty()
					
					&& !jTFscoer.getText().isEmpty()){
				System.out.println("actionPerformed(). 插入");
				insertProcess();
			}
		
		else if(e.getActionCommand().equals("更新")
					&& !jTFSNo.getText().isEmpty()
					&& !jTFcourse.getText().isEmpty()
					){
				System.out.println("actionPerformed(). 更新");
				updateProcess();//验收
			}
		
//		else if(e.getActionCommand().equals("删除当前记录")){
//				System.out.println("actionPerformed(). 删除当前记录");
//				deleteCurrentRecordProcess();
//			}
		}
	
     /*
	
	public static void main(String[] args) {
		scoer  getcon = new  scoer();
   }

	*/
	
	public static String temp_proNo;
	
	public void queryProcess(String sQueryField)
	{
		temp_proNo = sQueryField;
		
		dbProcess.pro_queryProcess();
		
		studentVector.clear();
		
        while (!dbProcess.list.isEmpty()) {
            
      	  //System.out.print(dbProcess.list.poll());
      	  	Vector v = new Vector();
				v.add(dbProcess.list.poll());
				v.add(dbProcess.list.poll());
				v.add(dbProcess.list.poll());
				v.add(dbProcess.list.poll());
				studentVector.add(v);
        }
        
			studentJTable.updateUI();

			dbProcess.disconnect();
	}
	
	public static String sum = "";
	public static String checked = "";
	
	public void queryAllProcess()
	{
		  dbProcess.pro_queryAllProcess();	                 
	          
		  studentVector.clear();
		  
		  sum = dbProcess.list.size() / 4 + "";
		  checked = dbProcess.list_sum.size() + "";
		  dbProcess.list_sum.clear();
		  
		  jTFcourse.setText(checked + "/" + sum);
		  
          while (!dbProcess.list.isEmpty()) {
      
        	  //System.out.print(dbProcess.list.poll());
        	  	Vector v = new Vector();
				v.add(dbProcess.list.poll());
				v.add(dbProcess.list.poll());
				v.add(dbProcess.list.poll());
				v.add(dbProcess.list.poll());
				studentVector.add(v);
          }
          //
          studentJTable.updateUI();
          		
          System.out.println("读取完毕");
          
			dbProcess.disconnect();
	}
	
	//public static String temp_proNo;
	public static String temp_proCK;
	
	public void updateProcess()
	{
		temp_proNo = jTFSNo.getText().trim();
		temp_proCK = jTFcourse.getText().trim();
		
		dbProcess.pro_updataProcess();	
		
		studentVector.clear();
		
      	dbProcess.disconnect();
	}
	
	public static String temp_proName;
	public static String temp_teaNo;
	public void insertProcess()
	{
		System.out.println("准备申报");
		
		temp_proNo = jTFSNo.getText().trim();
		temp_proName = jTFSName.getText().trim();
		temp_proCK = jTFcourse.getText().trim();
		temp_teaNo = jTFscoer.getText().trim();
		
		dbProcess.pro_insertProcess();	
		
		System.out.println("申报成功");
		
		studentVector.clear();
		
      	dbProcess.disconnect();
	}
	
}
