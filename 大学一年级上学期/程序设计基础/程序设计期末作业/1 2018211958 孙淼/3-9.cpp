//计科2班 2018211958 孙淼
using namespace std;
int main(){
	int x;
	cout<<"输入一个数判断是否为质数"<<endl;
	while(cin>>x){
	for(int i=2;i<x;i++){
		if(x%i==0) cout<<"不是质数"<<endl;
		else  cout<<"是质数"<<endl;break;
	}
}
	return 0;
}


输入一个数判断是否为质数
7
是质数
6
不是质数

	
	
