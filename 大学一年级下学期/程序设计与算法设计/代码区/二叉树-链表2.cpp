#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

struct node{
	char data;
	node *lchild;
	node *rchild;
};

class BiTree{
	public:
		node *root;
		BiTree(){root==NULL;}
		int height(node *root);
		node *create();
}; 

node *  BiTree::create(){
	char val;
	cin>>val;
	if(val=='#'){
		return NULL;
	}
	else{
		node *current=new node();
		current->data=val;
		current->lchild=create();
		current->rchild=create();
		return current;
	}
}

int BiTree::height(node *root){
	if(root==NULL) return 0;
	int height=0;
	stack<node *> nodes;
	stack<int> tag;
	while(root !=NULL || !nodes.empty()){
		while(root!=NULL){
			nodes.push(root);
			tag.push(0);
			root=root->lchild;
		}
		if(tag.top()==1){
			int h=nodes.size();
			height=max(height,h); 
			nodes.pop();
			tag.pop();
			root=NULL;
		}
		else{
            root=nodes.top();
			root=root->rchild;
			tag.pop();
			tag.push(1);
		}
	}
	return height;
} 


int main(){
	BiTree a;
	node *root;
	root=a.create();
	int x=a.height(root);
	cout<<x;
}
