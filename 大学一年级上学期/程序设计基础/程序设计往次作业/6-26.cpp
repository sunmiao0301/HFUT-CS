//计科二班  孙淼  2018211958
#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	int m,n,j1=0;
	cout<<"输入行数m和列数n"<<endl;
	cout<<"m= ";cin>>m;
	cout<<"n= ";cin>>n;
	int matrix[m][n];
	int matrix1[n][m];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			srand(j1);
			matrix[i][j]=rand()%9;
			matrix1[j][i]=matrix[i][j];
			cout<<matrix[i][j]<<" ";
			j1++;
		}
		    cout<<endl;
	}
cout<<endl;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cout<<matrix1[i][j]<<" ";
		}
		cout<<endl;
	}
	
return 0;
} 
