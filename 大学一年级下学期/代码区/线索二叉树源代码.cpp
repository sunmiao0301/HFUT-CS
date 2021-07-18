#include <iostream>
#include <string> 
#include "tree.h"
using namespace std;
int main(){
	tree Bitree;
	cout<<"输入根结点的数据"<<endl;
	string n;
	cin>>n;
	Bitree.root->data=n;
	cout<<"每层高度从左向右输入，以”#“结束（#代表之后没有结点）"<<endl;
	Bitree.nbuild(Bitree.root);
	cout<<endl;
	Bitree.preorder(Bitree.root);
	cout<<endl;
	Bitree.inorder(Bitree.root);
	cout<<endl;
	Bitree.postorder(Bitree.root);
	cout<<endl;
    Bitree.nbclue(Bitree.root);
    Bitree.postClueOrder(Bitree.root);
    cout<<endl;

return 0; 
} 
