//计科2班 2018211958 孙淼
#include<iostream> 
using namespace std;
int main(){
	int number;
	cout<<"你考试考了多少分？（0~100）"<<endl;
	cin>>number;
	if(0<=number<60) cout<<"差"<<endl;
	else if(60<=number<80) cout<<"中"<<endl;
	else if(80<=number<90) cout<<"良"<<endl;
	else if(90<=number<=100) cout<<"优"<<endl;
	getchar();
	return 0;	 
}







你考试考了多少分？（0~100）
60
差

--------------------------------
Process exited after 4.536 seconds with return value 0
请按任意键继续. . .
