//计科2班 2018211958 孙淼
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main(){
	int n;
	srand(time(0));
	int num=rand()%100+1;
	cout<<"输入一个数："<<endl;
	cin>>n;
	do{
		if(n!=num)
		    if(n>num){
		   	cout<<"n>num"<<endl;
		   }
		   else{
		   	cout<<"n<num"<<endl;
		   }
		else{
			cout<<"n=mun"<<endl;break;
		} 
		cin>>n;  
	}while(1);
	return 0;
	
} 





输入一个数：
50
n>num
40
n>num
30
n>num
10
n<num
20
n>num
15
n<num
16
n<num
18
n>num
17
n=mun

--------------------------------
Process exited after 23.88 seconds with return value 0
请按任意键继续. . .
