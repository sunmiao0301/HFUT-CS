package ChatRoom;




import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.*;

public class addFriend {
	JFrame frame;
	JLabel ip_l;
	JLabel friendname_l;
	JLabel friendport_l;
	JTextField ip_t;
	JTextField friendname_t;
	JTextField friendport_t;
	JButton add_friend;
	JLabel friend_info;
	addFriend(Member member){
		//设置frame
		frame=new JFrame("添加好友");
		frame.setBounds(200,250,250,285);
		frame.setLayout(null);
		//设置标签头
		friend_info=new JLabel("请输入好友信息",JLabel.CENTER);
		friend_info.setBounds(0,10,250,30);
		frame.add(friend_info);
		//设置ip标签
		ip_l=new JLabel("好友IP地址:");
		ip_l.setBounds(10, 50, 75, 30);
		frame.add(ip_l);
		//设置ip文本框
		ip_t=new JTextField("127.0.0.1");
		ip_t.setBounds(80, 50, 145, 30);
		frame.add(ip_t);
		
		//设置好友名标签
		friendname_l=new JLabel("好友用户名:");
		friendname_l.setBounds(10, 100, 75, 30);
		frame.add(friendname_l);
		//填写好友名
		friendname_t=new JTextField();
		friendname_t.setBounds(80, 100, 145, 30);
		frame.add(friendname_t);
		//设置好友端口标签
		
		friendport_l=new JLabel("好友端口号:");
		friendport_l.setBounds(10, 150,75, 30);
		frame.add(friendport_l);
		//填写好友端口
		friendport_t=new JTextField("");
		friendport_t.setBounds(80, 150, 145, 30);
		frame.add(friendport_t);
	
		//设置添加键
		add_friend=new JButton("添加");
		add_friend.setBounds(75, 200, 100, 30);
		frame.add(add_friend);
		frame.setResizable(false);
		frame.setVisible(true);
		
		add_friend.addMouseListener(new MouseAdapter(){
			public void mouseClicked(MouseEvent m){
				friend f=new friend(ip_t.getText(),friendname_t.getText(),friendport_t.getText());
				member.updata_data(f);
				member.friend_array.add(f);
				frame.dispose();
			}
		});
	}
}


