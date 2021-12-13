//计科2班 2018211958 孙淼
#include <iostream>
using namespace std;

class DateType{
	public:
		DateType(char a,int b,float c);
		void setDate(char a,int b,float c);
		void showDate();
		private:
			float x,y,z;
}; 

DateType::DateType(char a,int b,float c){
	x=(float) a;
	y=(float) b;
	z=c;
}

void DateType::setDate(char a,int b,float c){
	x=(float) a;
	y=(float) b;
	z=c;
}

void DateType::showDate(){
	cout<<x+y+z<<endl;
}

int main(){
	DateType d1(0,0,0);
	d1.showDate();
	DateType d2('A',2,2.55);
	d2.showDate();
	return 0;
}

0
69.55

--------------------------------
Process exited after 0.6352 seconds with return value 0
请按任意键继续. . .
