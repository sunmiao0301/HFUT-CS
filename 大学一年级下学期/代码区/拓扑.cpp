#include<iostream>
using namespace std;

int s[10][10];
int ind[10];
int visit[10];
int a[10];
int edge=14,num=10;

void topology(int n){
	if(n==num){
		for(int i=0;i<num;i++)
		  cout<<a[i]+1<<" ";
		cout<<endl;
		return ;
	}
	for(int i=0;i<num;i++){
		if((ind[i]==0)&&(visit[i]==0)){
			for(int j=0;j<num;j++)
				if(s[i][j])
				  ind[j]--;			
			a[n]=i;
			visit[i]=1;
			topology(n+1);
		for(int k=0;k<num;k++)	
		   if(s[i][k]==1)
		     ind[k]++;
		    visit[i]=0;
		}		
	}
	return ;
}

int main(){ 
	for(int i=0;i<10;i++)
	  for(int j=0;j<10;j++)
	    cin>>s[i][j];
	for(int i=0;i<10;i++)
	  cin>>ind[i];
	for(int i=0;i<10;i++) 
	  visit[i]=0;
	  cout<<endl;
	  topology(0);
}


