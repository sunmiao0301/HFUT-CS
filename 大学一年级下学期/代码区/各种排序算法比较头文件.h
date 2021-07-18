#ifndef SORT_H
#define SORT_H
#include <iostream>
using namespace std;
inline int change(int &a,int &b){
	int c=a;a=b;b=c;
}
void SelectionSort(int a[],int n){         
	for(int k=0;k<(n-1);k++){
		int max=k;
		for(int m=k+1;m<n;m++){	
			if(a[m]>a[max])
			max=m;
		}
		if(a[max]!=a[k]){
			change(a[max],a[k]);
		}			
	}
} 

void InsertionSort(int a[],int n){
	for(int i=1;i<n;i++){
		int temp=a[i];
		int j=i-1;
		while((a[j]<temp)&&(j>=0)){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
} 

void ShellSort(int a[],int n){
	int d=n/2;               
	while(d>0){
	    for(int i=d;i<n;i++){
		    int temp=a[i];
		    int j=i-d;
		    while(j>=0&&a[j]<temp){
		    	a[j+d]=a[j];
		    	j-=d;
			} 
		a[j+d]=temp;
	    } 
	d=d/2;	
	}
	
}

void partition(int a[],int n,int begin,int end,int &mid){
	int x=a[begin];
	while(begin!=end){
		while(begin<end&&a[end]<x) end--;
		if(begin<end){
			a[begin]=a[end];
			begin++;
		}
		while(begin<end&&a[begin]>x) begin++;
		if(begin<end){
			a[end]=a[begin];
			end--;
		}
	}
	a[begin]=x;
	mid=begin;
}
void QuickSort(int a[],int n,int begin,int end){
	int mid;
	if(begin<end){
		partition(a,n,begin,end,mid);
		QuickSort(a,n,begin,mid-1);
		QuickSort(a,n,mid+1,end);
	}
} 

void screen(int a[],int k,int n){
	int x=a[k];
	bool finished=0;
	int i=k;int j=2*i;         
	while(j<=n&&!finished){    
		if(j<n&&a[j]>a[j+1]) j++;
		if(x<=a[j]) finished=1;
		else{
			a[i]=a[j];
			i=j;
			j=2*j;
		} 
	}
	a[i]=x;
} 

void HeapSort(int a[],int n){
	for(int i=n/2-1;i>=0;i--) screen(a,i,n);
	for(int i=n-1;i>=1;i--){
		change(a[i],a[0]);
		screen(a,0,i-1);
	}	
}
int getDigit(int i, int d)    
{                              
    int val;
    while (d--)
    {
        val = i % 10;
        i /= 10;
    }
    return val;
}

void RadixSort(int *list,int n,int digit){
    int i=0,j=0;
    int *count=new int[10];   
    int *bucket=new int[n];
    for (int d=1; d<=digit;d++){
        for (i=0;i<10;i++) count[i]=0;  
		          
        for (i=0;i<n;i++){
            j=getDigit(list[i],d);
            count[j]++;
        }
        for (i=8;i>=0;i--)
            count[i]=count[i]+count[i+1]; 
        for (i=n-1;i>=0;i--){
            j=getDigit(list[i],d);
            bucket[count[j]-1]=list[i];
            count[j]--;
        }
        for (i=0,j=0;i<n;i++,j++)
            list[i]=bucket[j];
    }
}
#endif
