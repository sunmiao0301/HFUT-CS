//¼Æ¿Æ¶ş°à   Ëïíµ   2018211958
#include <iostream>
using namespace std; 
class BaseClass{
	public:
		virtual ~ BaseClass();   
};

BaseClass::~BaseClass(){
	cout<<"BaseClass destructor"<<endl;
}                                 

class DerivedClass:public BaseClass{
	public:
		~DerivedClass();     
}; 

DerivedClass::~DerivedClass(){
	cout<<"DerivedClass destructor"<<endl;
}

int main(){
	BaseClass *p=new DerivedClass();
	delete p;                            
    return 0; 
}
