#include<iostream>
#include<string>
using namespace std;

int main(){
	int heighet=0; 
	char a[10];
	char e;
	int f;
	for(int i=0;i<10;i++){
		cin>>e;
		a[i]=e;
	}
	int b[10];
	int c[10];
	for(int i=0;i<10;i++){
		cin>>f;
		b[i]=f;
	}
	for(int i=0;i<10;i++){
		cin>>f;
		c[i]=f;
	}
	for(int i=9;i>=0;i--){
		int n=1;
		int w=b[i];
		while(w!=-1){
			w=b[w];
			n++;
		}
	  if(n>heighet) heighet=n;	
	}
	cout<<"Ê÷µÄ¸ß¶È£º"<<heighet;	
}




