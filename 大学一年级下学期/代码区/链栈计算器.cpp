#include<iostream>
#include<string>
using namespace std;

struct node{
		int date;
		node * next;
		node(const int &l):date(l),next(NULL){};
	};
	
class stack1{
	public:
	    stack1();
	    ~stack1(); 
	    bool empty()const;
	    int get_top(char &x)const;
	    int push(const char x);
	    int pop();
	private:
		int count;
		node * top;
		char date;
};

stack1::stack1() {count=0; top=NULL;}

stack1::~stack1(){ while (! empty() ) pop();}

bool stack1::empty()const{
	if (count==0) return true;
	return false;
}

int stack1::get_top(char &x)const{
	if ( empty() ) return 0;
	else{
		x=top->date;
		return 1;
	}
} 

int stack1::push(const char x){
	node * s=new node(0);
	s->date=x;
	s->next=top;
	top=s;
	count++;
	return 1;
}

int stack1::pop(){
	if ( empty() ) return 0;
	node * s=new node(0);
	s=top;
	top=top->next;
	delete s;
	count--;
	return 1;
}

class stack2{
	public:
	    stack2();
	    ~stack2();
	    bool empty_2()const;
	    int get_top_2(int &x)const;
	    int push_2(const int x);
	    int pop_2();
	private:
		int count;
		node * top;
		int date;
};

stack2::stack2() {count=0; top=NULL;}

stack2::~stack2() {while( !empty_2()) pop_2();}

bool stack2::empty_2()const{
	if (count==0) return true;
	return false;
}

int stack2::get_top_2(int &x)const{
if ( empty_2() ) return 0;
	else{
		x=top->date;
		return 1;
	}
} 

int stack2::push_2(const int x){
	node * s=new node(0);
	s->date=x;
	s->next=top;
	top=s;
	count++;
	return 1;
}

int stack2::pop_2(){
	if ( empty_2() ) return 0;
	node * s=new node(0);
	s=top;
	top=top->next;
	delete s;
	count--;
	return 1;
}

int jisuan(char x,int a,int b){
	int s;
	switch(x){
		case '+':
			s=a+b;
			break;
		case '-':
			s=a-b;
			break;
		case '*':
			s=a*b;
			break;
		case '/':
		    s=a/b;
			break; 
	return s;
}
}

int zhuanhuan(int u,char e){
	int a;
	switch(e){
		case '#':
			a=0;
			break;
		case '(':
			if(u==1) a=5;
			else a=1;
			break;
		case ')':
			a=1;
			break;
		case '+':
		case '-':
			a=2;
			break;
		case '*':
		case '/':
			a=3;
			break;	
	}
	return a;
}

int main(){
	stack1 a;
	stack2 b;
	string s;
	cout<<"ÇëÊäÈëÔËËãÊ½£º"<<endl;
	cin>>s;
	int changdu=s.size();
	a.push(s[0]);
	for(int i=1;i<changdu;i++){
		int shuzi;
		if(s[i]>='0' && s[i]<='9') {
			shuzi=s[i]-'0';
			int w=i;
			while(s[w+1]>='0' && s[w+1]<='9'){
				w++;
				shuzi=shuzi*10+(s[w]-'0');
			}
			i=w;
			b.push_2(shuzi);
		}
		else{
			int o,p;
			char zhanding;
			char r=s[i];
			a.get_top(zhanding);
			o=zhuanhuan(1,s[i]);
			p=zhuanhuan(0,zhanding);
			while(p>=o){
				if(p==o){
					 if(p<=1){
						a.pop();
						i++;
					}
					else if(p>1){
						char l;
						a.get_top(l);
						int m,n;
						b.get_top_2(m);
						b.pop_2();
						b.get_top_2(n);
						b.pop_2();
						int jieguo=jisuan(l,n,m);
						b.push_2(jieguo);
						a.pop();
					}
				}
				else if(p>o){
						char ll;
						a.get_top(ll);
						int mm,nn;
						b.get_top_2(mm);
						b.pop_2();
						b.get_top_2(nn);
						b.pop_2();
						int jieguo1=jisuan(ll,nn,mm);
						b.push_2(jieguo1);
						a.pop();	
				}
			a.get_top(zhanding);
			o=zhuanhuan(1,s[i]);
			p=zhuanhuan(0,zhanding);
			}
			if(p<o){
				a.push(s[i]);
			}
		}
	}
	int assc;
	b.get_top_2(assc);
	cout<<assc;
}
