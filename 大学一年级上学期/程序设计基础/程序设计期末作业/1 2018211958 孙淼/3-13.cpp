//计科2班 2018211958 孙淼
#include<iostream>
using namespace std;
unsigned Fibonnacci(unsigned n){
	unsigned F;
	if (n==3) F=2;
	else if (n==4)	 F=3;  
	else F=Fibonnacci(n-1)+Fibonnacci(n-2); 
	return F;
}


int main(){
	unsigned n;
	cin>>n;
	unsigned y=Fibonnacci(n);
	cout<<y<<endl;
	return 0;
}



6
8

--------------------------------
Process exited after 3.73 seconds with return value 0
请按任意键继续. . .
