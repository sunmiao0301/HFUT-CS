package computer_net;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

public class client {
	public static void main(String[] args) throws IOException, InterruptedException {
		File file1 = new File("./src/computer_net/1.png");//传送文件目录
		File file2 = new File("./src/computer_net/4.png");//接受文件目录
		//其实读取要传送的文件是不需要createNewFile()的
		/*if(!file1.exists()) {
			file1.createNewFile();
		}*/
		if(!file2.exists()) {
			file2.createNewFile();
		}
		ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
		CloneStream(byteArrayOutputStream, new FileInputStream(file1));
		//协议的选择
		GBN client = new GBN("localhost",7070,8080);//目标服务器端口8080，本地客户端端口7070
		
		System.out.println("Start to send file 1.png to " + "localhost " + 7070);
		client.send(byteArrayOutputStream.toByteArray());
		System.out.println("\nStart to receive file 3.png from " + "localhost " + 7070);
		while (true) {
			byteArrayOutputStream = client.receive();
			if (byteArrayOutputStream.size() != 0) {
				FileOutputStream fileOutputStream = new FileOutputStream(file2);
				fileOutputStream.write(byteArrayOutputStream.toByteArray(), 0, byteArrayOutputStream.size());
				fileOutputStream.close();
				System.out.println("Get the file ");
				System.out.println("Saved as 4.png");
				break;
		}
			
		Thread.sleep(50);
	}
}
		/**
		 * clone the input stream to a ByteArrayOutputstream object
		 * 
		 * @param CloneResult the clone result of input stream
		 * @param InputStream the input stream to be cloned
		 * @throws IOException when read input stream, some exception occur
		 */
		//将输入流转为字节数组对象
		static void CloneStream(ByteArrayOutputStream CloneResult, InputStream InputStream) throws IOException {
		//InputStream Inputstream
		byte[] buffer = new byte[1024];
		int length;
		while ((length = InputStream.read(buffer)) != -1) {//？
			CloneResult.write(buffer, 0, length);
		}
		CloneResult. flush();
	}
}
