//计科2班 2018211958 孙淼
#include<iostream>
using namespace std;
int main(){
	char t;
	cout<<"Menu:A(dd)D(elete)S(ort)Q(uit),Select one:"<<endl;
	cin>>t;
	while(t!= 'Q')
	{
	
       switch(t){
         case 'A':
	     {
		 cout<<"数据已经增加"<<endl;break;}
	     case 'D':
	     {	
	  cout<<"数据已经删除"<<endl;break;}
         case 'S':
         	{
	  cout<<"数据已经排序"<<endl;break;}
	} 
	      cin>>t;
   
	    }
	   return 0 ;	
}





Menu:A(dd)D(elete)S(ort)Q(uit),Select one:
A
数据已经增加
S
数据已经排序
D
数据已经删除
Q

--------------------------------
Process exited after 6.794 seconds with return value 0
请按任意键继续. . .	
