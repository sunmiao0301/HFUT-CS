//计科二班  孙淼  2018211958
#include <iostream>
#include <cstring>
using namespace std;
int main(){
	cout<<"输入一句英文句子"<<endl;
    string s;int sum;
    cin>>s;   
    for(int i=0;i<s.length();i++){
    	if (toupper(s[i])<='Z'&&toupper(s[i]>='A'))
    	sum=sum+1;
	}
	cout<<endl<<sum;
}

