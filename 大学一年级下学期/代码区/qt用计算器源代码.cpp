#include <iostream>
#include <string>
#include "calculate.h" 

int main(){
	cout<<"请输入式子，并以\"#\"开始和结束,"<<endl;
	string str1;
	cin>>str1;
	while(!normalize(str1))	cin>>str1;	
	cout<<calculate(str1)<<endl;
	cout<<"要继续，请输入Y"<<endl;
	string b;
	cin>>b;
	if(b=="Y"||b=="y") goto L1; 
	system("pause");
return 0; 
}
