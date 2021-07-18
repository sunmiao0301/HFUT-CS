#include<iostream>
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
	node *current=NULL;
	char val;
	cin>>val;
	if(val=='#'){
		return NULL;
	}
	else{
		current=new node();
		current->data=val;
		current->lchild=create();
		current->rchild=create();
		return current;
	}
}

int BiTree::height(node *root){
	if(root==NULL)
	   return 0;
	int leftheight=height(root->lchild);
	int rightheight=height(root->rchild);
	return (leftheight>rightheight)?(leftheight+1):(rightheight+1);
}

int main(){
	node *root;
	BiTree a;
	cout<<"按前序排序创建二叉树:"<<endl;
	root=a.create();
	cout<<a.height(root);
}
