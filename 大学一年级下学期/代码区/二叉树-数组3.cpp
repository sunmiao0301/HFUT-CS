#include<iostream>
#include<queue>
using namespace std;

int main(){
	char *a;
	int *b;
	int *c;
	int num;
	int height=0;
	cout<<"请输入结点个数:";
	cin>>num;
	a=new char[num];
	b=new int[num];
	c=new int[num];
	for(int i=0;i<num;i++)
	  cin>>a[i];
	for(int i=0;i<num;i++)
	  cin>>b[i];
	for(int i=0;i<num;i++)
	  cin>>c[i];
	queue<int> q;
	if(num>0){
		q.push(0);
		while(!q.empty()){
			height++;
			int width=q.size();
	    for(int i=0;i<width;i++){
	    	int x=q.front();
	    	q.pop();
	    	for(int j=x;j<10;j++){
	    		if(b[j]==x){
	    	  	  q.push(j);
			  }
			} 
		  }
		}
		cout<<height;
	} 
	else cout<<"树的高度为0";
} 
