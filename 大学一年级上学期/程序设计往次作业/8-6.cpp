//计科二班  孙淼   2018211958
#include <iostream>
using namespace std;
const float pi=3.1415;
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
		void getPerim(); 
};
void rectangle::print(){
	cout<<"另一边长为 "<<a2<<endl;
}

void rectangle::getArea(){
	cout<<"矩形面积为 "<<a1*a2<<endl;
}

void rectangle::getPerim(){
	cout<<"矩形周长为 "<<2*(a1+a2)<<endl;
}


class circle:public shape{
	public:
		circle(float r1):shape(r1){}
		void getArea(){
			cout<<"圆的面积为 "<<a1*a1*pi<<endl;
		}
		void print();
		void getPerim(); 
};


void circle::print(){
	cout<<"半径为初始半径 "<<a1<<endl;
}

void circle::getPerim(){
	cout<<"圆的周长为 "<<2*pi*a1<<endl;
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
    s1.getPerim();
    circle s2(n);
    s2.circle::print();
    s2.getArea();
    s2.getPerim();
    return 0;
}
   

/*
请输入n为初始边长/半径
6.543
请输入长方形的另一条边长
5.345
初始边长/半径为 6.543
另一边长为 5.345
矩形面积为 34.9723
矩形周长为 23.776
半径为初始半径 6.543
圆的面积为 134.49
圆的周长为 41.1097

--------------------------------
Process exited after 49.88 seconds with return value 0
请按任意键继续. . .

