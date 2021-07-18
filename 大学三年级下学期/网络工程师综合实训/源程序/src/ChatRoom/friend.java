package ChatRoom;

import java.net.InetAddress;
import java.net.UnknownHostException;

//好友的主机地址以及端口
public class friend{
	InetAddress friend_inetAddress;
	String friend_name;
	int friend_port;
	friend(String address,String name){
		try {
			friend_inetAddress=InetAddress.getByName(address);
			friend_name=name;
			friend_port=8888;
		} catch (UnknownHostException e) {
			e.printStackTrace();
		}
	}
	
	friend(String address,String name,String friend_port){
		try {
			friend_inetAddress=InetAddress.getByName(address);
			friend_name=name;
			this.friend_port=Integer.valueOf(friend_port).intValue();
		} catch (UnknownHostException e) {
			e.printStackTrace();
		}
	}
}