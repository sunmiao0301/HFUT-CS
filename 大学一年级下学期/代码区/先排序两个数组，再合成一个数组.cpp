#include <iostream>
using namespace std;
int main(){
	int a[10];
	int b[10];
	int *c=new int [30];
	cout<<"请输入数组a:";
	for(int i=0;i<10;i++)
	  cin>>a[i];
	cout<<"请输入数组b:";
	for(int j=0;j<10;j++)
	  cin>>b[j];
	for(int q=0;q<9;q++){
		for(int p=0;p<9-q;p++){
			if(a[p]>a[p+1]){
				int temp=a[p];
			a[p]=a[p+1];
			a[p+1]=temp;
			}	
		}
	}
	cout<<"排序后的a数组:";
	for(int i=0;i<10;i++)
	  cout<<a[i]<<" ";
	cout<<endl;
	for(int e=0;e<9;e++){
		for(int f=0;f<9-e;f++){
			if(b[f]>b[f+1]){
				int temp=b[f];
			b[f]=b[f+1];
			b[f+1]=temp;
			}
		}
	}
	cout<<"排序后的b数组:";
	for(int j=0;j<10;j++)
	  cout<<b[j]<<" ";
	cout<<endl;
	for(int t=0;t<10;t++)
	  c[t]=a[t];
	  int w=0;
	for(int x=0;x<10;x++){
		while(b[x]>c[w]){
			w++;
		}
		if(b[x]>c[9+x]) c[10+x]=b[x];
		else{
			for(int y=10+x;y>w;y--)
		   c[y]=c[y-1];
		c[w]=b[x];
		}
	}
	for(int u=0;u<20;u++)
	  cout<<c[u]<<" ";
}
