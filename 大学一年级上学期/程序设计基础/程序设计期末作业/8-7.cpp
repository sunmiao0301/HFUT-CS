//计科2班 2018211958 孙淼
#include<iostream>
using namespace std;
class Point{
	public:
	   Point(int a,int b){x=a,y=b;};
	   Point operator++(int);
	   Point& operator++();
	   Point operator--(int);
	   Point& operator--();
	   Point display(){cout<<"("<<x<<","<<y<<")";}
	private:
	   int x,y;   	  
};

Point& Point::operator++(){
	x++;
	y++;
	return *this;
};

Point Point::operator++(int){
	Point old=*this;
	++(*this);
	return old;
};

Point& Point::operator--(){
	x--;
	y--;
	return *this;
};

Point Point::operator--(int){
	Point old=*this;
	--(*this);
	return old;
};

int main(){
	Point a(2,3);
	(a++).display();
	(++a).display();
	(a--).display();
	(--a).display();
} 



(2,3)(4,5)(4,5)(2,3)
--------------------------------
Process exited after 0.2268 seconds with return value 0
请按任意键继续. . .

