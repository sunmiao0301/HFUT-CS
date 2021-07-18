#ifndef TREE_H                       //二叉树 
#define TREE_H
#include <iostream>
#include <string> 
#include <stack>
using namespace std;
struct node{
	string data;
	node* Lnode;
	node* Rnode;
	node* father; 
	int Ltag;
	int Rtag;
};

class tree{
public: 
	tree();
	void preorder(node *t);
	void inorder(node *t);
	void postorder(node *t);
	void nbuild(node *t);   
	void nbclue(node *t);
	void postClueOrder(node *t);
	node *root;
	node *pre;
};

tree::tree(){
    root=new node;
    root->Lnode=0;
    root->Rnode=0;
    root->father=0;
    pre=0;
}

void tree::preorder(node *t){
	if(t!=0){
		cout<<t->data<<"  ";
		preorder(t->Lnode);
		preorder(t->Rnode);		
	}
}

void tree::inorder(node *t){
	if(t!=0){
		inorder(t->Lnode);
		cout<<t->data<<"  ";
		inorder(t->Rnode);
	}
}

void tree::postorder(node *t){
	if(t!=0){
		postorder(t->Lnode);
		postorder(t->Rnode);
		cout<<t->data<<"  ";
	}
}

void tree::nbuild(node *t){
if(t!=0){ 
	for(int i=1;i<=2;i++){
		node *s=new node;
	    string n;
	    cout<<"请输入数据"<<endl; 
	    cin>>n;
	    if(n!="#"){                  //规定数据为#时为空 
	    	s->data=n;
	        s->father=t;
	        s->Lnode=0;
	        s->Rnode=0;
	        if(i==1) t->Lnode=s;
	        else t->Rnode=s;
		}
	    if(n=="#"){
	    	if(i==1) t->Lnode=0;
			if(i==2) t->Rnode=0; 
		}	
	}
	nbuild(t->Lnode);
    nbuild(t->Rnode);   
}            	  
}

void tree::nbclue(node *t){                 //后序线索化二叉树 
    if (t->Lnode!=0)
    	nbclue(t->Lnode);
	 
	if (t->Rnode!=0)
    	nbclue(t->Rnode);
	 
	if(t!=0){
		if(t->Lnode==0){
			t->Ltag=1;                       //即为前驱 
			t->Lnode=pre;
		}
		else  t->Ltag=0;
		if(pre!=0 && pre->Rnode==0){
			pre->Rtag=1;                     //后继
			pre->Rnode=t; 
		}
		else if(pre!=0) 
            pre->Rtag=0;
		pre=t;				
	}
}

void tree::postClueOrder(node *root){
	node *t=root;
	while(!(t->Ltag==1&&t->Rtag==1)){
		while(t->Ltag!=1)
		    t=t->Lnode;
		if(t->Rtag==0)
		    t=t->Rnode;
	}                     //找到第一个结点 
	
	while(t->father!=0){
		cout<<t->data<<"  ";
		if(t->Rtag==0){
			if(t==t->father->Rnode||t->father->Rtag==1) t=t->father;
			else{ 
			   t=t->father->Rnode;
			   	    while(!(t->Ltag==1&&t->Rtag==1)){
		                while(t->Ltag!=1)
		                    t=t->Lnode;
		                if(t->Rtag==0)
		                    t=t->Rnode;
			        }			    
			}   
	    }	
	    else{
	    	t=t->Rnode;
		}
    }
    cout<<root->data<<"  ";
   
}


#endif

