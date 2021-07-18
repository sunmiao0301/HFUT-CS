#include <iostream>
using namespace std;
struct node{
	int data;
	node *next;
}; 
class list{
	public:
		list();
		~list();
		int length()const;
		void create(int n);
		int get(const int i,int &x)const;
		int insert(const int i,const int x);
		int delete_data(const int i);
		int print();
		node *& get_ptr(int pos);	
	private:
		int count;
		node *head; 
};
list::list(){
	head=new node;
	head->next=NULL;
	count=0;
}
void list::create(int n){
	int x;int y=1;
	cin>>x;
	node *rear=head;
	while(y!=n){
		count++;
		node *s=new node;
		s->data=x;
		rear->next=s;
		rear=s;
		rear->next=NULL;
		cin>>x;
		y++;
	}
}

int list::length()const{
	node *p=head->next;
	int n=0;
	while(p!=NULL){
		n++;
		p=p->next;
	}
	return n;
}

int list::get(const int i,int &x)const{
	node*p;
	p=head->next;
	int j=1;
	while(p!=NULL&&j!=i){
		p=p->next;
		j++;
	}
	if(p==NULL){
		cout<<"error"<<endl;
		return 0;
	}
	x=p->data;
    return 1;
}

int list::insert(const int i,const int x){
	node *p;
	p=head;
	int j=0;
	while(p!=NULL&&j!=i){
		p=p->next;j++;
	}
	if(i<1||i>count+1){
		cout<<"error"<<endl;
		return 0;
	}
	node *s=new node;
    s->data=x;
	s->next=p->next;
	p->next=s; 
	count++;
	return 1;
}

int list::delete_data(const int i){
	node *p;node *u;
	p=head;
	int j=0;
	while(p!=NULL&&j!=i){
		p=p->next;j++;
	}
	if(i<1||i>count+1){
		cout<<"error"<<endl;
		return 0;
	}
    u=p->next;
    p->next=u->next;
	delete u;
	count--;
	return 1; 
}

int list::print(){
	node *p=head->next;
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
}

list::~list(){
	for(int i=1;i<=count;i++){
	    delete_data(i);
	}
}

node*& list::get_ptr(int pos){
	if(pos==0) return head;
	node * p=head;
	for(int i=1;i<pos;i++)
	  p=p->next;
	return p->next;
}  

int main(){
	list l1;list l2;
	cout<<"输入第一个链表,最后一个数作为结束标志"<<endl;
	l1.create(11);
	cout<<"输入第二个链表,最后一个数作为结束标志"<<endl;
	l2.create(11);
	cout<<endl;
	node *p=l1.get_ptr(0);
	node *q=l2.get_ptr(1);
    while(p->next!=NULL)
    p=p->next;
    p->next=q;
    delete l2.get_ptr(0);
    cout<<"输出连接后的链表"<<endl;
    l1.print();
    cout<<endl;
    cout<<"输出排序后的链表"<<endl;
    for(int i=1;i<=20;i++){
    	for(int j=1;j<=20-i;j++){
    		node *p=l1.get_ptr(j);
    		node *pn=l1.get_ptr(j+1);
    		if(p->data>pn->data){
    			node *c=l1.get_ptr(j-1);
    			c->next=pn;
    			p->next=pn->next;
    			pn->next=p;
			}
		}
	}
	l1.print();
	return 0;
} 




