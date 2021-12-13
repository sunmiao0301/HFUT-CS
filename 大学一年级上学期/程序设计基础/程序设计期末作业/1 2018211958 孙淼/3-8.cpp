//计科2班 2018211958 孙淼
#include<iostream>
using namespace std;
double power(double F){
	double C=((double)5/9)*(F-32);
	return C;
}


int main(){
	int F;
	cout<<"输入一个华氏温度，转化后输出相应的摄氏温度"<<endl;
	cin>>F;
	cout<<"C="<<power(F)<<endl;
	return 0;
	
}



输入一个华氏温度，转化后输出相应的摄氏温度
50
C=10

--------------------------------
Process exited after 2.634 seconds with return value 0
请按任意键继续. . .

