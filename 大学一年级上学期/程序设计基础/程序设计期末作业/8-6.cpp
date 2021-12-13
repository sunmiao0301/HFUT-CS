//计科2班 2018211958 孙淼 
#include<iostream>
using namespace std;
class Shape{
	public:
		virtual getArea()=0;
		virtual getPerim()=0;
	private:
		int n;
};

class Rectangle:public Shape{
	public:
		Rectangle(int c,int k){
			a=c;
			b=k;
		}
		int getArea(){
			int m=a*b;
			return m;
		};
		int getPerim(){
			int z=2*a+2*b;
			return z;
		};
	private:
	    int a,b;	
};

class Circle:public Shape{
	public:
		Circle(float R){
			r=R;
		}
		float getArea(){
			float Pi=3.14;
			float m=Pi*r*r;
			return m;
		};
		float getPerim(){
			float Pi=3.14;
			float z=2*Pi*r;
			return z;
		};
	private:
		float r;
};

int main(){
	Rectangle x(2,3);
	cout<<x.getArea()<<endl;
	cout<<x.getPerim()<<endl;
	Circle y(3);
	cout<<y.getArea()<<endl;
	cout<<y.getPerim()<<endl;
}

6
10
28.26
18.84

--------------------------------
Process exited after 0.1329 seconds with return value 0
请按任意键继续. . .

