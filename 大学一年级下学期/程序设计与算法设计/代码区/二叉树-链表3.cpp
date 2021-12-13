#include<iostream>
#include<queue>
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
	if(root==NULL) return 0;
	queue<node *> q;
	q.push(root);
	int height=0;
	while(!q.empty()){
		height++;
		int width=q.size();
		for(int i=0;i<width;i++){
			root=q.front();
		    q.pop();
		    if(root->lchild!=NULL) q.push(root->lchild);
		    if(root->rchild!=NULL) q.push(root->rchild);
		}
	}
	return height;
} 


int main(){
	BiTree a;
	node *root;
	root=a.create();
	int h=a.height(root);
	cout<<h; 
}
