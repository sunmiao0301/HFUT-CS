#include <iostream>
#include <string>
#include "compress.h"
#include "decompress.h"
using namespace std;
int main(){
	int count[26]={0};              
	string code[26];                 
	static int n=0;                  
	int c;
	count1(count);
	for(int i=0;i<26;i++)
	{
		if(count[i]!=0) n++; 
	}
	element hufftree[2*n-1]; 
	createHuffman(hufftree,n,count);    
	cout<<endl<<"编码中..."<<endl;
	encode(hufftree,code,count,n);       
	for(int i=0;i<26;i++)
	{             
		if(count[i]!=0)
		cout<<"字母 "<<char(i+65)<<" 的编码为："<<code[i]<<endl;			
	}	
	int len=trans(code,c);
	cout<<"压缩完成！"<<endl;
    cout<<"解压中..."<<endl; 
	decompress(read(len,c),code); 
	cout<<"解压缩完成！"<<endl;                                   
	system("pause");
return 0; 
}
