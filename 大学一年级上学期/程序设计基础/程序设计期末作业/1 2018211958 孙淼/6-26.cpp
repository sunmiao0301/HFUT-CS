//计科2班 2018211958 孙淼
#include <iostream>
using namespace std;
int main(){
	int x,y,temp;
	cin>>x>>y;
	int a[x][y];
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
		  cin>>a[i][j];
		  cout<<a[i][j]<<" ";
		}
      cout<<endl;
	}
	cout<<endl;
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			temp=a[i][j];
			a[i][j]=a[j][i];
			cout<<a[i][j]<<" ";
			a[i][j]=temp;
		}
		cout<<endl;
	}
}

4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

1 5 9 13
2 6 10 14
3 7 11 15
4 8 12 16

--------------------------------
Process exited after 21.56 seconds with return value 0
请按任意键继续. . .
