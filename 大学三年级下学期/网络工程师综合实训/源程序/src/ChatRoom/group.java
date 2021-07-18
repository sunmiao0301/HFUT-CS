package ChatRoom;

import java.net.InetAddress;
import java.net.UnknownHostException;

//群聊的主机地址以及端口
public class group{
	InetAddress group_inetAddress;
	String group_name;
	group(String address,String name){
		try {
			group_inetAddress=InetAddress.getByName(address);
			group_name=name;
		} catch (UnknownHostException e) {
			e.printStackTrace();
		}
	}
}