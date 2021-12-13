#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "sort.h" 
using namespace std;
int main(){
L1: 
    int n;
	cout<<"请输入数据规模:";
	cin>>n; 
	int i=0;
	int *arr1=new int[n];int *arr2=new int[n];int *arr3=new int[n];
	int *arr4=new int[n];int *arr5=new int[n];int *arr6=new int[n]; 
	ofstream fout("数组.txt"); 
	srand((unsigned)time(NULL)); 
	do{
		arr1[i]=rand()%20001;
		arr6[i]=arr5[i]=arr4[i]=arr3[i]=arr2[i]=arr1[i];
		fout<<arr1[i]<<" ";
		i++;
	}while(i<n);
	cout<<"共 "<<n<<" 个数据已产生完毕"<<endl;		
    clock_t start2=clock();
	ShellSort(arr3,n);       
	clock_t end2=clock();
	cout<<"希尔插入排序用时为 "<< (double)(end2-start2) / CLOCKS_PER_SEC << " 秒" << endl;
	ofstream fout3("希尔排序数组.txt"); 
	for(int k=0;k<n;k++)    fout3<<arr3[k]<<" "; 
	delete[] arr3;
	clock_t start3=clock();
	QuickSort(arr4,n,0,n-1);       
	clock_t end3=clock();
	cout<<"快速排序用时为 "<< (double)(end3-start3) / CLOCKS_PER_SEC << " 秒" << endl;	
	ofstream fout4("快速排序数组.txt"); 
	for(int k=0;k<n;k++)    fout4<<arr4[k]<<" ";
	delete[] arr4;
    clock_t start4=clock();
	HeapSort(arr5,n);       
	clock_t end4=clock();
	cout<<"堆排序用时为 "<< (double)(end4-start4) / CLOCKS_PER_SEC << " 秒" << endl;	
	ofstream fout5("快速排序数组.txt"); 
	for(int k=0;k<n;k++)    fout5<<arr5[k]<<" ";
	delete[] arr5;
    clock_t start5=clock();
	RadixSort(arr6,n,5);       
	clock_t end5=clock();
	cout<<"基数排序用时为 "<< (double)(end5-start5) / CLOCKS_PER_SEC << " 秒" << endl; 	
	ofstream fout6("基数排序数组.txt"); 
	for(int k=0;k<n;k++)    fout6<<arr6[k]<<" "; 
	delete[] arr6;
	delete[] arr1;
	delete[] arr2;	
    cout<<"要重新输入数据，请输入Y或y"<<endl;
    char a;
    cin>>a;
    if(a=='Y'||a=='y')  goto L1;
	else system("pause");	 
return 0;
}
