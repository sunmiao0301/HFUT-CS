#ifndef DECOMPRESS_H
#define DECOMPRESS_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

template <class T>
string Itos(T a){
	ostringstream os;
	os<<a;
	return os.str();
}

string exchange(int x)
{
   int i=x;
   string a;
   while(i)
   {
    a=Itos(i%2)+a;
    i/=2; 
   }
   return a;
}

string read(int len,int c){
	ifstream f1("t2.txt");
	string result;
	int i=1;
	char ch;
	while(f1.get(ch)){                                  
		string b=exchange(int(ch));
		int L=b.length();
		if(L<7){
			for(int i1=0;i1<7-L;i1++) 
				b="0"+b;
			if(i==len)
			    b=b.substr(0,c);
		}
		else if(i==len&&c!=0){
			b=b.substr(0,c);			
		}		
		result=result+b;		    		
	    i++;                       		                  		   		
	}
	return result; 
}

void decompress(string result,string code[]){
	ofstream f3("t3.txt");
	int k=1;
	for(int i=0;i<result.length();){		
		string check=result.substr(i,k);
		int i1=0;
		for(;i1<26;i1++){
			if(code[i1]==check){
				f3<<char(i1+65);
				break;
			}		
		}
		if(i1==26) {
			k++;
			continue;
		}
		else{
		    i=i+k;
		    k=1;	
		}
	}
}
#endif
