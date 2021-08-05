package compiler;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import java.awt.*;

public class huibian extends JFrame {

	//private static final long serialVersionUID = 8766059377195109228L;
	private static String title;
	private static String fileName;
	private static TextArea text;
	
	private static boolean isInteger(String word) {
		int i;
		boolean flag = false;
		for (i = 0; i < word.length(); i++) {
			if (Character.isDigit(word.charAt(i))) {
				continue;
			} else {
				break;
			}
		}
		if (i == word.length()) {
			flag = true;
		}
		return flag;
	}
	
	public huibian() {
		init();
		
	}
public huibian(String title,String fileName){//huibian inf = new huibian("目标代码生成", fourElementPath);
	this.title=title;
	this.fileName=fileName;
	int count = 0;
	init();
	this.setTitle(title);
	try {
		String str[] =readFile(fileName).split("\n");
		String str_1 = "生成的目标代码如下\n";
		String str_2 = "序号（OP,ARG1，ARG2）\n";
		text.append(str_1);
		text.append(str_2);
		for(int i = 2; i < str.length; i++)
		{
			String temp[] = str[i].split(",");
			if(temp[0].charAt(temp[0].length() -1) == '='){//=
				
				//if(temp[1].substring(0,temp[1].length()-1).equals("T"))
				//{
				//String temp1 = temp[0].substring(0,temp[0].length() - 2) + "\n";
				//text.append(temp1);	
				//}
				//else {
				String temp1 = ++count + " MOV " + temp[3].substring(0,temp[3].length() - 1) + "," + temp[1] + "\n";
				//System.out.println(temp1);
				text.append(temp1);
				//}
			}
			//++
			else if(temp[0].charAt(temp[0].length() -1) == '+' && temp[0].charAt(temp[0].length() -2) == '+'){
				String temp1 = ++count + " INC "  + temp[1] + "\n";
				//System.out.println(temp1);
				text.append(temp1);
			}
			//+
			else if(temp[0].charAt(temp[0].length() -1) == '+'){
				
				//if(isInteger(temp[1])) {
					String temp2 = ++count + " MOV " + "AX" + "," + temp[2] + "\n";
					String temp3 = ++count + " MOV " +  temp[3].substring(0,temp[3].length() - 1) + "," + temp[1] + "\n";
					String temp1 = ++count + " ADD " + temp[3].substring(0,temp[3].length() - 1) + "," + "AX" + "\n";//temp[3].substring(0,temp[3].length() - 1)
					text.append(temp2);
					text.append(temp3);
					text.append(temp1);
				//}
				//else {
				//String temp1 = temp[0].substring(0,temp[0].length() - 2) + " ADD " + temp[3].substring(0,temp[3].length() - 1) + "," + temp[1] + "\n";//temp[3].substring(0,temp[3].length() - 1)
				//System.out.println(temp1);
				//text.append(temp1);
				//}
			}
			//-
			else if(temp[0].charAt(temp[0].length() -1) == '-'){
				//String temp1 = ++count + " SUB " + temp[3].substring(0,temp[3].length() - 1) + "," + temp[1] + "\n";
				String temp2 = ++count + " MOV " + "AX" + "," + temp[2] + "\n";
				String temp3 = ++count + " MOV " +  temp[3].substring(0,temp[3].length() - 1) + "," + temp[1] + "\n";
				String temp1 = ++count + " SUB " + temp[3].substring(0,temp[3].length() - 1) + "," + "AX" + "\n";//temp[3].substring(0,temp[3].length() - 1)
				text.append(temp2);
				text.append(temp3);
				text.append(temp1);
				//System.out.println(temp1);
				//text.append(temp1);
			}
			//*
			else if(temp[0].charAt(temp[0].length() -1) == '*'){
				//String temp1 = ++count + " MUL " + temp[3].substring(0,temp[3].length() - 1) + "," + temp[1] + "\n";
				String temp2 = ++count + " MOV " + "AX" + "," + temp[2] + "\n";
				String temp3 = ++count + " MOV " +  temp[3].substring(0,temp[3].length() - 1) + "," + temp[1] + "\n";
				String temp1 = ++count + " MUL " + temp[3].substring(0,temp[3].length() - 1) + "," + "AX" + "\n";//temp[3].substring(0,temp[3].length() - 1)
				text.append(temp2);
				text.append(temp3);
				text.append(temp1);
				//System.out.println(temp1);
				//text.append(temp1);
			}
			///
			else if(temp[0].charAt(temp[0].length() -1) == '/'){
				//String temp1 = ++count + " DIV "  + temp[3].substring(0,temp[3].length() - 1) + "," + temp[1] + "\n";
				String temp2 = ++count + " MOV " + "AX" + "," + temp[2] + "\n";
				String temp3 = ++count + " MOV " +  temp[3].substring(0,temp[3].length() - 1) + "," + temp[1] + "\n";
				String temp1 = ++count + " DIV " + temp[3].substring(0,temp[3].length() - 1) + "," + "AX" + "\n";//temp[3].substring(0,temp[3].length() - 1)
				text.append(temp2);
				text.append(temp3);
				text.append(temp1);
				//System.out.println(temp1);
				//text.append(temp1);
			}
			//RJ
			else if(temp[0].charAt(temp[0].length() -1) == 'J' && temp[0].charAt(temp[0].length() -2) == 'R'){
				String temp1 = ++count + " JMP " + temp[3].substring(0,temp[3].length() - 1)  + "\n";
				//System.out.println(temp1);
				text.append(temp1);
			}
			//FJ
			else if(temp[0].charAt(temp[0].length() -1) == 'J' && temp[0].charAt(temp[0].length() -2) == 'F'){
				//String temp1 = temp[0].substring(0,temp[0].length() - 3) + " JZ " + temp[3].substring(0,temp[3].length() - 1)  + "\n";
				//String temp1 = temp[0].substring(0,temp[0].length() - 3) + " JMP " + temp[3].substring(0,temp[3].length() - 1)  + "\n";
				String temp1 = ++count + " JL " + temp[3].substring(0,temp[3].length() - 1)  + "\n";
				//System.out.println(temp1);
				text.append(temp1);
			}
			//>
			else if(temp[0].charAt(temp[0].length() -1) == '>'){
				String temp1 = ++count + " CMP " + temp[1] + "," + temp[2]  + "\n";
				//String temp2 = temp[0].substring(0,temp[0].length() - 2) + " JG " + temp[3].substring(0,temp[3].length() - 1)  + "\n";
				//System.out.println(temp1);
				text.append(temp1);
				//text.append(temp2);
			}
			//<
			else if(temp[0].charAt(temp[0].length() -1) == '<'){
				String temp1 = ++count + " CMP " + temp[1]  + "," + temp[2]  + "\n";
				//String temp2 = temp[0].substring(0,temp[0].length() - 2) + " JL " + temp[3].substring(0,temp[3].length() - 1)  + "\n";
				//System.out.println(temp1);
				text.append(temp1);
				//text.append(temp2);
			}
		}
		
	} catch (IOException e) {
		
		e.printStackTrace();
	}	
}
	private void init() {
		Toolkit toolkit = Toolkit.getDefaultToolkit();
		Dimension screen = toolkit.getScreenSize();
		setSize(500, 400);
		super.setLocation(screen.width / 2 - this.getWidth() / 2, screen.height
				/ 2 - this.getHeight() / 2);
		setContentPane(createContentPane());
	}

	private Container createContentPane() {
		JPanel pane = new JPanel(new BorderLayout());
		text = new TextArea();
		//msg.setBackground(Color.green);
		text.setForeground(Color.BLUE);
		pane.add(BorderLayout.CENTER, text);
		return pane;
	}
	private String readFile(String filename) 
	throws IOException{
		StringBuilder sbr = new StringBuilder();
		String str;
			FileInputStream fis = new FileInputStream(filename);
			BufferedInputStream bis = new BufferedInputStream(fis);
			InputStreamReader isr = new InputStreamReader(bis, "UTF-8");
			BufferedReader in=new BufferedReader(isr);
			while((str=in.readLine())!=null){
				sbr.append(str).append('\n');
			}
			in.close();
			//text.setText(sbr.toString());
		return sbr.toString();
	}
	public static String getTitl() {
		return title;
	}

	public static void setTitl(String title) {
		huibian.title = title;
	}

	public static String getFileName() {
		return fileName;
	}

	public static void setFileName(String fileName) {
		huibian.fileName = fileName;
	}

	public static TextArea getText() {
		return text;
	}

	public static void setText(TextArea jText) {
		huibian.text = jText;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		huibian inf=new huibian("测试","test.txt");
inf.setVisible(true);
	}

}
