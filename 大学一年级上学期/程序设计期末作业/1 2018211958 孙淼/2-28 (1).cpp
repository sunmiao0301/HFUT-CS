//计科2班 2018211958 孙淼
#include<iostream>
using namespace std;
int main(){
	char n;
	cout<<"Menu:A(dd)D(elete)S(ort)Q(uit),Select One:"<<endl;
	cin>>n;
	while(1){
	   if (n=='A'){ 
		   cout<<"数据已经增加"<<endl;} 
	   
	   else if (n=='D'){
	   
		   cout<<"数据已经删除"<<endl;}
	   
	   else if(n=='S'){
	   
	   	   cout<<"数据已经排序"<<endl;}
	   	else if(n=='Q')   {
	   		;break;
		   }
    
	    cin>>n;
	   }  
		return 0;
}






Menu:A(dd)D(elete)S(ort)Q(uit),Select One:
A
数据已经增加
D
数据已经删除
S
数据已经排序
Q

--------------------------------
Process exited after 8.512 seconds with return value 0
请按任意键继续. . .	   	   
     
	  
	  
	
 
