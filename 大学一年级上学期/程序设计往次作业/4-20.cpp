//计科二班 孙淼 2018211958 
#include <iostream>
using namespace std;
class Complex{
	public:
		Complex(double s=0,double x=0);
		void add(Complex b);
		void show();
	private:
		double t,y; 
};

Complex::Complex(double s,double x){
        t=s;
	    y=x;
}

void Complex::add(Complex b){
	t=t+b.t;
	y=y+b.y;
}

void Complex::show(){
	cout<<t<<"+"<<y<<"i"<<endl;
}

int main(){
	Complex c1(3,5);
	Complex c2=4.5;
	c1.add(c2);
	c1.show();
}

/*7.5+5i

--------------------------------
Process exited after 0.2179 seconds with return value 0
请按任意键继续. . .
*/




