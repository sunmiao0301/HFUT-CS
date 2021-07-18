//计科二班  孙淼  2018211958
#include <iostream>
using namespace std;
const float pi=3.14;
class shape{
	public:
	float a1;
	shape(float a);
	void print();
};

shape::shape(float a){
	a1=a;
}

void shape::print(){
	cout<<"初始边长/半径为 "<<a1<<endl;
}


class rectangle:public shape{
	public:
		float a2;
		rectangle(float a,float b):shape(a){
			a2=b;
		}	
		void getArea();
		void print();
};
void rectangle::print(){
	cout<<"另一边长为 "<<a2<<endl;
}

void rectangle::getArea(){
	cout<<"矩形面积为 "<<a1*a2<<endl;
}


class square:public rectangle{
	public:	
	square(float m):rectangle(m,m){}
	void getArea(){
		cout<<"正方形面积为 "<<a1*a2<<endl;
	}
	void print();
};


void square::print(){
	cout<<"边长为初始边长 "<<a1<<endl;
}


class circle:public shape{
	public:
		circle(float r1):shape(r1){}
		void getArea(){
			cout<<"圆的面积为 "<<a1*a1*pi<<endl;
		}
		void print();
};


void circle::print(){
	cout<<"半径为初始半径 "<<a1<<endl;
}


int main(){
	float m,n;
	cout<<"请输入n为初始边长/半径"<<endl;
	cin>>n;
	cout<<"请输入长方形的另一条边长"<<endl;
	cin>>m;
    rectangle s1(n,m);
    s1.shape::print();
    s1.print();
    s1.getArea();
    square s2(n);
    s2.square::print();
    s2.getArea();
    circle s3(n);
    s3.circle::print();
    s3.getArea();
    return 0;
}








/*
请输入n为初始边长/半径
3.123
请输入长方形的另一条边长
6.72
初始边长/半径为 3.123
另一边长为 6.72
矩形面积为 20.9866
边长为初始边长 3.123
正方形面积为 9.75313
半径为初始半径 3.123
圆的面积为 30.6248

--------------------------------
Process exited after 8.849 seconds with return value 0
请按任意键继续. . .
*/
