//计科2班 2018211958 孙淼
#include<iostream>
using namespace std;
class BaseClass{
	public:
		virtual ~BaseClass(){cout<<"BaseClass指针已经删除"<<endl;}; 
};

class DerivedClass:public BaseClass{
	public:
		~DerivedClass(){cout<<"DerivedClass指针已被删除"<<endl;}
};

int main(){
	BaseClass *b=new DerivedClass();
	delete b;
}

DerivedClass指针已被删除
BaseClass指针已经删除

--------------------------------
Process exited after 0.5249 seconds with return value 0
请按任意键继续. . .
 
