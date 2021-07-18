#include<iostream>
using namespace std;
#define maxlen 50
class queue{
	public:
		queue();
		bool empty()const;
		bool full()const;
		int get_front(int &x)const;
		int append(const int x);
		int serve();
	private:
		int count;
		int front,rear;
		int date[maxlen];
};

queue::queue(){count=0;front=rear=0;}

bool queue::empty()const{
    if (count==0) return true;
    return false;
}

bool queue::full()const{
    if (count==maxlen-1) return true;
    return false;
}

int queue::get_front(int &x)const{
    if( empty() ) return 0;
    x=date[ (front+1)%maxlen ];
    return 1;
}

int queue::append(const int x){
	if ( full() ) return 0;
	rear=(rear+1)%maxlen;
	date[rear]=x;
	count++;
	return 1;
}

int queue::serve(){
	if(empty() ) return 0;
	front=(front+1)%maxlen;
	count--;
	return 1;
}

int Out_Number(int n){
	int s1,s2;
	queue Q;
	for(int i=1;i<n;i++)
	  cout<<"  ";
	cout<<1<<endl;
	Q.append(1);
	for(int j=2;j<=n;j++){
		for(int k=j;k<n;k++)
		  cout<<"  ";
		s1=0;
		for(int l=1;l<=j-1;l++){
		   Q.get_front(s2);
		   Q.serve();
		   if((s1+s2)>9) cout<<s1+s2<<"  ";
		   else cout<<s1+s2<<"   ";
		   Q.append(s1+s2);
		   s1=s2;
		}
		cout<<1<<endl;
		Q.append(1);
	}
}

int main(){
	int n;
	cout<<"请输入杨辉三角的行数"<<endl;
	cin>>n;
	Out_Number(n);
}
