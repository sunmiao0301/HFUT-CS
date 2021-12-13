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
	list l1;
	list l2;
	cout<<"请输入链表l1，最后一个数为结束标志:";
	l1.create(11);
	cout<<"请输入链表l2，最后一个数为结束标志:";
	l2.create(11);
	for(int i=1;i<=10;i++){
    	for(int j=1;j<=10-i;j++){
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
	cout<<"输出排序后的l1链表:";
	l1.print();
	cout<<endl;
	for(int i=1;i<=10;i++){
    	for(int j=1;j<=10-i;j++){
    		node *p=l2.get_ptr(j);
    		node *pn=l2.get_ptr(j+1);
    		if(p->data>pn->data){
    			node *c=l2.get_ptr(j-1);
    			c->next=pn;
    			p->next=pn->next;
    			pn->next=p;
			}
		}
	}
	cout<<"输出排序后的l2链表:";
	l2.print();
	cout<<endl;
	for(int i=0;i<10;i++){
		node*p=l2.get_ptr(1); 
		l2.head->next=p->next;
		node*first=l1.get_ptr(1);
		node*last=l1.head;
		while(last->next!=NULL){
			last=last->next;
		}
		if(p->data<=first->data){
			p->next=l1.head->next;
			l1.head->next=p; 
		}
		else if(p->data>=last->data){
			last->next=p;
		}
		else if(first->data<p->data && p->data<last->data){
			int t=1;
			while(p->data>first->data){
			first=first->next; 
			t++;
		}
		node*e=l1.get_ptr(t-1);
		e->next=p;
		p->next=first;
	}
}
    l1.print(); 
}
