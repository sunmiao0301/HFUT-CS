package ChatRoom;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.*;

public class addGroup {
	JFrame frame;
	JLabel ip_l;
	JLabel groupname_l;
	JTextField ip_t;
	JTextField groupname_t;
	JButton add_group;
	JLabel group_info;
	addGroup(Member member){
		//设置frame
		frame=new JFrame("加入群组");
		frame.setBounds(200,200,250,235);
		frame.setLayout(null);
		//设置标签头
		group_info=new JLabel("请输入群组信息",JLabel.CENTER);
		group_info.setBounds(0,10,250,30);
		frame.add(group_info);
		
		//设置ip标签
		ip_l=new JLabel("群组IP地址:");
		ip_l.setBounds(10, 50, 75, 30);
		frame.add(ip_l);
		//设置ip文本框
		ip_t=new JTextField("224.0.0.1");
		ip_t.setBounds(80, 50, 145, 30);
		frame.add(ip_t);
		
		//设置好友名标签
		groupname_l=new JLabel("  群组名称:");
		groupname_l.setBounds(10, 100, 75, 30);
		frame.add(groupname_l);
		//填写好友名
		groupname_t=new JTextField();
		groupname_t.setBounds(80, 100, 145, 30);
		frame.add(groupname_t);
		
		//设置添加键
		add_group=new JButton("加入");
		add_group.setBounds(75,150, 100, 30);
		frame.add(add_group);
		frame.setResizable(false);
		frame.setVisible(true);
		
		add_group.addMouseListener(new MouseAdapter(){
			public void mouseClicked(MouseEvent m){
				group g=new group(ip_t.getText(),groupname_t.getText());
				member.updata_data(g);
				member.group_array.add(g);
				frame.dispose();
			}
		});
	}
}

