//计科2班 2018211958 孙淼 
template<class T>
void mySwap(T &x,T &y){
	T temp=x;
	x=y;
	y=temp;
}

template<class T>
void bubbleSort(T a[],int n){
	int i=n-1;
	while(i>0){
		int lastExchangeIndex=0;
		for(int j=0;j<i;j++)
		 if(a[j+1]<a[j]){
		 	mySwap(a[j],a[j+1]);
		 	lastExchangeIndex=j;
		 }
		i=lastExchangeIndex;
	}
}

template<class T>
int binSearch(const T list[],int n,const &key){
	int low=0;
	int high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(key==list[mid])
		  return mid+1;
		else if(key<list[mid])
		  high=mid-1;
		else 
		  low=mid+1;    
	}
	return -1;
}

#include<iostream>
using namespace std;
int main(){
	int data1[]={1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14};
	bubbleSort(data1,17);
	int n;
	cout<<"请输入一个数"<<endl;
	cin>>n;
	cout<<"该数在第"<<binSearch(data1,17,n)<<"位";
}	
	
请输入一个数
4
该数在第4位
--------------------------------
Process exited after 1.299 seconds with return value 0
请按任意键继续. . .	
	
	
	
	
	
	
	

