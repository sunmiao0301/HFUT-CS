//计科2班 2018211958 孙淼
#include <iostream>
using namespace std;
class Shape{
	public:
		int n;
};

class Rectangle:public Shape{
	public:
	int a,b;
	void getArea(){
		cout<<"the area is: "<<a*b<<endl;
	}
};

class Circle:public Shape{
	public:
	int r;
	float PI=3.14;
	void getArea(){
		float p=PI*r*r;
		cout<<"the area is: "<<p<<endl;
	}
};

class Square: public Rectangle{
	public:
	int x;
	void getArea(){
		cout<<"the area is："<<x*x;
	}
};

int main(){
	Rectangle t;
	t.a=2;
	t.b=3;
	t.getArea();
	Circle c;
	c.r=4;
	c.getArea();
	Square s;
	s.x=3;
	s.getArea();
}


the area is: 6
the area is: 50.24
the area is: 9
--------------------------------
Process exited after 0.4491 seconds with return value 0
请按任意键继续. . .

