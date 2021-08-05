package compiler;

public class FourElement {
int id;//四元式序号，为编程方便
String op;//操作符
String arg1;//第一个操作数
String arg2;//第二个操作数
Object result;//结果
public FourElement(){
	
}
public FourElement(int id,String op,String arg1,String arg2,String result){
	this.id=id;
	this.op=op;
	this.arg1=arg1;
	this.arg2=arg2;
	this.result=result;	
}
}
