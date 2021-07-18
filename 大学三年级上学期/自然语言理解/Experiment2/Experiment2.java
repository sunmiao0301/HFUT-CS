package my_project;
//随机生成
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.io.*;
import java.util.Scanner;

public class Experiment2 {
	public static void main(String args[]){
		Map<String,String> map=new HashMap<String,String>();//构造map
		ArrayList<String> sword=new ArrayList<String>();//构造动态数组
		ArrayList<String> dword=new ArrayList<String>();
		Pattern pattern=Pattern.compile("([\u4E00-\u9FA5]*)(.)");
		Matcher mat;
		Random random=new Random();
		int m,clen=100;
		Boolean exist[]=new Boolean[clen];
		for(int i=0;i<clen;i++){
			exist[i]=false;
		}
		try{
			String title="";
			String sw,dw;
			BufferedReader bsread=new BufferedReader(new FileReader("E:\\eclipse-workspace\\my_project\\src\\my_project\\txt\\sword.txt"));//读取实验1生成的文件
			BufferedReader bdread=new BufferedReader(new FileReader("E:\\eclipse-workspace\\my_project\\src\\my_project\\txt\\dword.txt"));	
			BufferedReader bfread=new BufferedReader(new FileReader(new File("E:\\eclipse-workspace\\my_project\\src\\my_project\\txt\\Ci.txt")));
			BufferedWriter bfwrite=new BufferedWriter(new FileWriter(new File("E:\\eclipse-workspace\\my_project\\src\\my_project\\txt\\Struct.txt")));
			String text=bfread.readLine();
			String sent="";
			String struc="";
			
			sw=bsread.readLine();//将若干sw，dw从文件中读取放入动态数组sword，dword中去
			while(sw!=null){
				sword.add(sw);
				sw=bsread.readLine();
			}
			dw=bdread.readLine();
			while(dw!=null){
				dword.add(dw);
				dw=bdread.readLine();
			}
			bsread.close();
			bdread.close();
			
			while(text != null){//
				if(text.length()<2){//去掉一些乱码
					text=bfread.readLine();
					continue;
				}else if(text.length()<6){//不到6则判定为标题，在下面存入标题中
					title=text;
				}else{
					if(map.containsKey(title)){//如果已有该title，则text继续读入下一行
						text=bfread.readLine();
						continue;
					}else{
						mat=pattern.matcher(text);//去掉词中的非汉字字符
						while(mat.find()){
							sent=mat.group(1);//取分段后的第一段
							int len=sent.length();//读取该段长度
							while(len>0){
								if(len>3){//如果是7个字符，则划分为223，如果是5个字符，则划分为23，以此类推
									struc+=2;//struc加上字符串'2'
									len-=2;//长度-2
								}else{
									struc+=len;//struc加上字符串为'该段长度'，如7，则此时就是3
									len=0;//该段长度置0
								}
							}
							struc+=mat.group(2);//开始处理分段后的第二段
						}
					    map.put(title, struc);//将得到的格式放入map
					    bfwrite.write(title+":"+struc+"\r\n");
					    struc="";
					}
					
				}

				text=bfread.readLine();//读取
			}
			bfwrite.close();
			bfread.close();

			System.out.println("请换行输入你想生成的宋词类型（词牌名形式）");//根据词牌名生成词
		}catch(Exception e){
			System.out.println(e);
		}
		Scanner input=new Scanner(System.in);
		String title=input.nextLine();//将输入的词牌名存入title
		input.close();
		String text;
		if(map.containsKey(title)){
			text=map.get(title);//取出对应的格式
			String output=title+"\n";//先将输出的词牌名写入输出
			for(int i=0;i<text.length();i++){//词的总字数text不够，则继续随机加词产生句子
				m=random.nextInt(clen);//随机产生0-100的数字
			    while(exist[m])
			    	m=random.nextInt(clen);
			    exist[m]=true;//text的格式是223这样
				if(text.charAt(i)=='1'){//charAt()返回指定索引位置的char值
					output+=sword.get(m).split(":")[0];//需要一个字符，给一个单字
				}else if(text.charAt(i)=='2'){
					output+=dword.get(m).split(":")[0];//需要两个字符，给一个双字
				}else if(text.charAt(i)=='3'){
					output+=sword.get(m).split(":")[0];//需要三个字符，给一双一单
					output+=dword.get(m).split(":")[0];
				}else{
					output+=(text.charAt(i)+"\n");	
				}
			}
			System.out.println(output);
		}else{
			System.out.println("请重新输入已存在的词牌名");
		}
	}
}
