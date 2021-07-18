#include <iostream>
using namespace std;
int main(){
	int a[10];
	int b[10];
	int c[20];
	int temp;
	cout<<"请输入数组a:";
	for(int i=0;i<10;i++)
	  cin>>a[i];
	cout<<"请输入数组b:";  
	for(int j=0;j<10;j++)
	  cin>>b[j];
	for(int i=0;i<10;i++)
	  c[i]=a[i];
	for(int i=0;i<10;i++)
	  c[10+i]=b[i];
	for(int i=0;i<19;i++){
		for(int j=0;j<19-i;j++)
		 if(c[j]>c[j+1]){
		 	temp=c[j];
		 	c[j]=c[j+1];
		 	c[j+1]=temp;
		 }
	}
	for(int i=0;i<20;i++)
	  cout<<c[i]<<" ";
} 
