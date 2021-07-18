#include<iostream>
using namespace std;

int main(){
	char *a;
	int *b;
	int *c;
	int *d;
	int num;
	cout<<"请输入结点个数:";
	cin>>num;
	a=new char[num];
	b=new int[num];
	c=new int[num];
	d=new int[num];
	for(int i=0;i<num;i++)
	  cin>>a[i];
	for(int i=0;i<num;i++)
	  cin>>b[i];
	for(int i=0;i<num;i++)
	  cin>>c[i];
	for(int i=0;i<num;i++)
	  d[i]=0;  
	for(int i=0;i<num;i++){
		if(b[i]==-1){
			d[i]=1;
		}
		else{
			d[i]=d[b[i]]+1;
		}
	}
	int height=0;
	for(int i=0;i<num;i++){
		if(d[i]>height)
		  height=d[i];
	}
	cout<<"树的高度为"<<height;
}
