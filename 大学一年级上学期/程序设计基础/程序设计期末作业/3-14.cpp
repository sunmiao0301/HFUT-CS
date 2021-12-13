//计科2班 2018211958 孙淼
#include<iostream>
using namespace std;
unsigned  Legendre(unsigned n,unsigned x){
	double p;
	if (n==0) p=1;
	else if (n==1) p=x;
	else  p=(2*n-1)*x*Legendre(n-1,x)-(n-1)*Legendre(n-2,x)/n;
	return p;
}



int main(){
	unsigned n,x;
	cin>>n>>x;
	unsigned y=Legendre(n,x);
	cout<<y<<endl;
	return 0;
}

0 5
1

--------------------------------
Process exited after 7.609 seconds with return value 0
请按任意键继续. . .


1 5
5

--------------------------------
Process exited after 12.18 seconds with return value 0
请按任意键继续. . .


2 5
75

--------------------------------
Process exited after 2.791 seconds with return value 0
请按任意键继续. . .






