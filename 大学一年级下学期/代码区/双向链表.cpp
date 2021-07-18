#include <iostream>
using namespace std;
struct node{
	int data;
	node* prior;
	node* next;
};

class doublelink{
    public:	
        int doublelink_insert(doublelink* ptr,int position,int member);	
        int doublelink_erase(doublelink* ptr, int position);	
        void doublelink_display(doublelink* ptr);	
        int doublelink_getlength(doublelink* ptr);
		int clear();
        int doublelink_nizhi(doublelink* ptr);
        doublelink()	{		
            head = new node;		
            head->prior = NULL;		
            head->next = NULL;		
            length = 0; 
        }
	private:
	    int length;
		node *head;	
};

int doublelink::doublelink_erase(doublelink* ptr, int position){
	if(ptr->length==0) cout<<"´íÎó";
	else{
		if(ptr->length==1){
			ptr->head->next=NULL;
			ptr->length--;
		}
		else{
			node *p=head->next;
			for(int i=0;i<position;i++)
			  p=p->next;
			p->next->prior=p->prior;
			p->prior->next=p->next;
			delete p;
			ptr->length--;
		}
	}
}

void doublelink::doublelink_display(doublelink* ptr){
	node *p=head->next;
	for(int i=0;i<ptr->length;i++){
		cout<<p->data<<" ";
		p=p->next;
	}
}

int doublelink::doublelink_insert(doublelink *ptr, int position, int member){
	node *p=new node;
	p->data=member;
	if(ptr->length==0){
		head->next=p;
		p->prior=head;
		p->next=NULL;
		ptr->length++;
	}
	else{
		if(position==0){
		    p->next=head->next;
		    head->next->prior=p;
		    p->prior=head;
			head->next=p; 
			ptr->length++;
		}
		else{
			node *pn=head->next;
			for(int i=1;i<position;i++)
			  pn=pn->next;
			p->next=pn;
			p->prior=pn->prior;
			pn->prior=p;
			ptr->length++;
		}
	}
}

int doublelink::doublelink_getlength(doublelink* ptr){
	return ptr->length;
}

int doublelink::clear(){
	while(head){
		node *p=head;
		head=head->next;
		delete p;
	}
	length=0;
}

int doublelink::doublelink_nizhi(doublelink* ptr){
    for(int i=1;i<ptr->length;i++){
    	node *p=head;
    	for(int j=1;j<=ptr->length;j++)
    	  p=p->next;
    	p->prior->next=NULL;
		node *t=head;
		for(int e=1;e<i;e++)
			t=t->next;
		p->prior->next=NULL;
		p->next=t->next;
		p->prior=t;
		t->next=p;
	}
}

int main(){
	doublelink *L=new doublelink;
	L->doublelink_insert(L,0,1);
	L->doublelink_insert(L,0,2);
	L->doublelink_insert(L,0,3);
	L->doublelink_insert(L,0,4);
	L->doublelink_insert(L,0,5);
	L->doublelink_insert(L,0,6);
	L->doublelink_insert(L,0,7);
	L->doublelink_insert(L,0,8);
	L->doublelink_insert(L,0,9);
	L->doublelink_display(L);
	cout<<endl;
	L->doublelink_nizhi(L);
	L->doublelink_display(L);
}
