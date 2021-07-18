package computer_net;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class server{
	public static void main(String[] args) throws IOException, InterruptedException {
			File file1 = new File("./src/computer_net/2.png");//接受文件目录
			File file2 = new File("./src/computer_net/3.png");//传送文件目录
			//产生file
			if (!file1.exists()) {
					file1.createNewFile();
			}
			//其实读取要传送的文件是不需要createNewFile()的
			/*if (!file2.exists()) {
					file2.createNewFile();
			}*/
			//GBN协议的服务器
			GBN server = new GBN("localhost", 8080, 7070);//目标客户端端口为7070，本地服务器端口为8080
			System.out.println("Start to receive file 1.png from "+"localhost "+ 8080);
			while (true) {
					ByteArrayOutputStream byteArrayOutputStream = server.receive();
					if (byteArrayOutputStream.size() != 0) {
						FileOutputStream fileOutputStream = new FileOutputStream(file1);
						fileOutputStream.write(byteArrayOutputStream.toByteArray(), 0, byteArrayOutputStream.size());
						fileOutputStream.close();
						System.out.println("Get the file ");
						System.out.println("Saved as 2.png");
						fileOutputStream.close();
						break;
					}
					Thread.sleep(50);
				}
				//捕获内存缓冲区的数据，转换成字节数组。
				ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
				client.CloneStream(byteArrayOutputStream, new FileInputStream(file2));
				System.out.println("\nStart to send file 3.png to" + "localhost" + 8080);
				server.send(byteArrayOutputStream.toByteArray());
		}
}
