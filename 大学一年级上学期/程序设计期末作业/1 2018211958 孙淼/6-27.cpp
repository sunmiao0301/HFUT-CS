//计科2班 2018211958 孙淼 
#include <iostream>
#include <string>
using namespace std;
class Employee{
	public:
		Employee(string mz,string dz,string cs,string yb);
	    setName(string x);
	    display();
	private:
		string name,location,city,postcode;
};

Employee::Employee(string mz,string dz,string cs,string yb){
	name=mz;
	location=dz;
	city=cs;
	postcode=yb;
}

Employee::setName(string n){
	name=n;
}
 
Employee::display(){
	cout<<name<<","<<location<<","<<city<<","<<postcode;
}


int main(){
	Employee zzt("郑振涛","合肥工业大学翡翠湖校区","蒙古","5438");
	zzt.display();
	cout<<endl;
	zzt.setName("猪头");
	zzt.display();
}

郑振涛,合肥工业大学翡翠湖校区,蒙古,5438
猪头,合肥工业大学翡翠湖校区,蒙古,5438
--------------------------------
Process exited after 0.2056 seconds with return value 0
请按任意键继续. . .
