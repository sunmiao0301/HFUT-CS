#ifndef COMPRESS_H
#define COMPRESS_H
#include <iostream>
#include <fstream>
#include <string>
#include <cmath> 
using namespace std;                 
struct element{
	int weight;                
	int Lchild,Rchild,parent;
};

void count1(int count[]){
	ifstream f1("t1.txt");
	int NumOfCha=0;
	char ch;	                          
	while(f1.get(ch)){                        
		    cout<<ch<<" ";
		    count[int(ch)-65]++;                    
		    NumOfCha++; 		
	}
	cout<<endl<<endl;
	for(int i=0;i<26;i++){
		if(count[i]!=0)	cout<<"字母 "<<char(i+65)<<" 的个数为 "<<count[i]<<endl; 	
	}	 
	cout<<"共有 "<<NumOfCha<<" 个字符" <<endl;			
}

void select(element hufftree[],int &i1,int &i2,int n);
void createHuffman(element hufftree[],int n,int count[]){	
	int w[n];
	int j=0;
	for(int i=0;i<26;i++){
		if(count[i]!=0){
			w[j]=count[i];
			j++;
		}
	}
	
//********************************** 
    
    for(int i=0;i<2*n-1;i++){
    	hufftree[i].parent=-1;
		hufftree[i].Lchild=-1;
		hufftree[i].Rchild=-1; 
	}	
	
	for(int i=0;i<n;i++)
	    hufftree[i].weight=w[i];  
    for(int i=n;i<2*n-1;i++)
	    hufftree[i].weight=0;         
	    
	    
	for(int k=n;k<2*n-1;k++){
		int i1,i2;                  
		select(hufftree,i1,i2,n);
		hufftree[i1].parent=k;
		hufftree[i2].parent=k;
		hufftree[k].weight=hufftree[i1].weight+hufftree[i2].weight;
		hufftree[k].Lchild=i1;
		hufftree[k].Rchild=i2;
	}
	
	cout<<"所建的哈夫曼树为：";
	for(int i=0;i<2*n-1;i++){
		if(i==n) cout<<"||  ";
		cout<<hufftree[i].weight<<"  ";		
	}
}
void select(element hufftree[],int &i1,int &i2,int n){
	int k1,k2;
	for(int i=0;i<2*n-1;i++){
	    if(hufftree[i].parent==-1){
	    	k1=i; 
			break;
		}		
    }
        for(int i=k1+1;i<2*n-1;i++){
	    if(hufftree[i].parent==-1){
	    	k2=i;
			break;
		}		
    }
	    for(int m=k1+1;m<2*n-1;m++){
		if(hufftree[m].parent==-1){
			if(hufftree[m].weight<hufftree[k1].weight&&hufftree[m].weight!=0)
				k1=m;	
		}
			else continue; 
	}
		i1=k1;
	    if(k1==k2) k2++;	
	for(int m=k2+1;m<2*n-1;m++){
		if(hufftree[m].parent==-1){
			if(hufftree[m].weight<hufftree[k2].weight&&hufftree[m].weight!=0&&m!=k1)
				k2=m;				
		}
		else continue;		 
	}
	    i2=k2;
	   }
void encode(element hufftree[],string code[],int count[],int n){
	int origin=0;	
	for(int i=0;i<n;i++)
	{
		for(int i1=origin;i1<26;i1++){
		    if (count[i1]!=0){
			    origin=i1;
			    break;                          
		    }		
	    }
		int k=i; 
	    while(k!=-1){
		    if(hufftree[hufftree[k].parent].Lchild==k)   
		   	    code[origin]="0"+code[origin];                            
			else if(hufftree[hufftree[k].parent].Rchild==k) 
			    code[origin]="1"+code[origin];
			k=hufftree[k].parent;	
		}
		origin++;	
	}	
} 
int trans(string code[],int &c){
	ifstream f1("t1.txt");
	ofstream f2("t2.txt");
	char ch;
	string a; 
	int lenOfF2=0;                   
	while(f1.get(ch)){                         
	    a=a+code[int(ch)-65];      	    		
	}
	for(int i=0;i<a.length();i=i+7){
		string b;
		if(i+7>a.length()){
			b=a.substr(i,a.length()%7);
			c=b.length();              
			for(int i2=0;i2<7-c;i2++)
			    b=b+"0";
		}
		else b=a.substr(i,7);		    		    
	    int sum=0;
		for (int i1=0;i1<b.length();i1++)
	        sum=sum+(int(b[i1])-48)*int(pow(2,b.length()-1-i1));
		f2<<char(sum);
		lenOfF2++;          		
	}
return lenOfF2;           
}
#endif
