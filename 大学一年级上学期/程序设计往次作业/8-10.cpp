//计科二班   孙淼   2018211958
#include <iostream>
using namespace std;
class Point{
	public:
		Point(float a,float b):x(a),y(b){}
		Point operator+(Point a);
		void get(Point a);
		friend Point operator+(Point a,float b);
		friend Point operator+(float b,Point a);
	private:
		float x;
		float y;
};
    void Point::get(Point a){
    	cout<<"（ "<<a.x<<" , "<<a.y<<" )";
	}
	
	Point Point::operator+(Point a){
	    return Point(x+a.x,y+a.y);	
	}
	
	Point operator+(Point a,float b){
		Point a1=a;
		a1.x+=b;
		a1.y+=b;
		return a1;
	}
	
	Point operator+(float b,Point a){
		Point a1=a;
		a1.x+=b;
		a1.y+=b;
		return a1;
	}
	
	
int main(){
	Point p1(7.124,3.12);
	Point p2(2.7,3.9);
	Point p3=p1+p2;
	p3.get(p3);
	(p1+3).get(p1+3);
	(3+p1).get(p1+3);
return 0;
} 
/*（ 9.824, 7.02 )（ 10.124, 6.12 )（ 10.124, 6.12 )
--------------------------------
Process exited after 0.108 seconds with return value 0
请按任意键继续. . .
*/