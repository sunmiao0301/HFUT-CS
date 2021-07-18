//计科二班  孙淼  2018211958
#include <iostream>
#include <string>
using namespace std;
class Employee{
	public:
		Employee(string name,string adress,string city,string postcode){
			n=name;
			a=adress;
			c=city;
			code=postcode;
		}
		void setName(string name){
			n=name;
		}
		void display();
	private:
		string n,a,c,code;
}; 

void Employee::display(){
	cout<<"名字为 "<<n<<endl;
	cout<<"地址为 "<<a<<endl;
	cout<<"城市为 "<<c<<endl;
	cout<<"邮编为 "<<code<<endl;
}

int main(){
	string n,a,c,code;
	cout<<"输入名字、地址、城市、邮编 "<<endl;
	cin>>n;cin>>a;cin>>c;cin>>code;
	Employee user(n,a,c,code);
	user.display();
	cout<<"请输入新名字"<<endl;
	cin>>n; 
	user.setName(n);
	user.display();
} 
