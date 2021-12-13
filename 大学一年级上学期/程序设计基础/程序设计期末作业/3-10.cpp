//计科2班 2018211958 孙淼
#include<iostream>
using namespace std;
int LCM(int x,int y){
	for(int i=x;i<=x*y;i++){
	if (i%x==0 && i%y==0){	return i;}
	}
	return 0;
}


int GCD(int x,int y){
	for (int i=x;i>0;i--){
		if (x%i==0 && y%i==0){
			return i;
		}
	}
	return 0;
}


int main(){
	int x,y;
	cout<<"输入两个正整数求他们的最小公倍数和最大公约数"<<endl;
	cin>>x>>y;
	cout<<LCM(x,y)<<endl;
	cout<<GCD(x,y)<<endl;
}


输入两个正整数求他们的最小公倍数和最大公约数
5 7
35
1

--------------------------------
Process exited after 4.496 seconds with return value 0
请按任意键继续. . .	
	
	



