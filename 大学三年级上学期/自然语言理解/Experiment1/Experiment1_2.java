package my_project;//试验1新闻部分

import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
public class Experiment1_2{//用于处理标点符号
    public static Boolean Is_label(String p){//标点符号判断函数
	    if(p.equals("。")||p.equals("，")||p.equals("；")||p.equals("：")||p.equals("？")||p.equals("！"))
		    return true;
		return false;
	}
	public static void main(String args[]){
		HashMap<String,Integer> sword=new HashMap<String,Integer>();
		HashMap<String,Integer> dword=new HashMap<String,Integer>();
		Pattern pat=Pattern.compile("(([\u4E00-\u9FA5]|。|，|；|：|？|！)*)(/)");
		String text="";
		try{
			BufferedReader bfread=new BufferedReader(new FileReader("E:\\eclipse-workspace\\my_project\\src\\my_project\\txt\\news.txt"));
		    text=bfread.readLine();
		    String Text="B";//text初始化为B，因为根据ngram读双节需要
		    while(text!=null){
		       Matcher mat=pat.matcher(text);
		    	while(mat.find()){
		    		if(Is_label(mat.group(1))){//如果是标点，加上EB，表示前后断开
		    			Text+="EB";
		    		}else{
		    		    Text+=mat.group(1);//否则，就将该划分段的汉字字符加入Text
		    		}
		    	}
		    	Text+="EE";//最后加上EE，用于保证最后一个双字是（字符）+E
		    	
		    	for(int i=0;i<Text.length()-1;i++){
		    		
		   			if(sword.containsKey(Text.substring(i,i+1))){//对单字的提取
		   				sword.put(Text.substring(i,i+1), sword.get(Text.substring(i,i+1))+1);//如果这单字已经有，则加1
		    		}else{
		    			sword.put(Text.substring(i,i+1), 1);//没有，则置1
		    		}
		    		
		    		if(Text.substring(i, i+2).equals("BB")||Text.substring(i, i+2).equals("EE")||Text.substring(i, i+2).equals("BE")||Text.substring(i, i+2).equals("EB"));
		    		else{
		    			if(dword.containsKey(Text.substring(i,i+2))){//对非字符双字的提取
		    				dword.put(Text.substring(i,i+2), dword.get(Text.substring(i,i+2))+1);//如果有，则加1
		    			}else{
		    				dword.put(Text.substring(i,i+2), 1);//没有，则置1
		    			}
		    		}
		    	}
		    	Text="B";
		    	text=bfread.readLine();
		    }
		    System.out.println("程序运行结束，请检查文件");
		    List<Map.Entry<String, Integer>> slist = new ArrayList<Map.Entry<String, Integer>>(sword.entrySet());  //将结果写入list
	        Collections.sort(slist, new Comparator<Map.Entry<String, Integer>>() {  
				public int compare(java.util.Map.Entry<String, Integer> o1, java.util.Map.Entry<String, Integer> o2) {
					return o2.getValue().compareTo(o1.getValue());
				}
	        }); 
			List<Map.Entry<String, Integer>> dlist = new ArrayList<Map.Entry<String, Integer>>(dword.entrySet());  
	        Collections.sort(dlist, new Comparator<Map.Entry<String, Integer>>() {  
				public int compare(java.util.Map.Entry<String, Integer> o1, java.util.Map.Entry<String, Integer> o2) {
					return o2.getValue().compareTo(o1.getValue());
				}
	        });
			bfread.close();
		
			BufferedWriter bwrite=new BufferedWriter(new FileWriter("E:\\eclipse-workspace\\my_project\\src\\my_project\\txt\\sword_news.txt"));//从list写入文件中去

			for(Map.Entry<String,Integer> key:slist){
				bwrite.write(key.getKey()+":"+key.getValue()+"\r\n");
			}
			bwrite.close();
			bwrite=new BufferedWriter(new FileWriter("E:\\eclipse-workspace\\my_project\\src\\my_project\\txt\\dword_news.txt"));
			for(Map.Entry<String,Integer> key:dlist){
				bwrite.write(key.getKey()+":"+key.getValue()+"\r\n");
			}
			bwrite.close();
		}catch(Exception e){
			System.out.println(e);
		}
	}
}
