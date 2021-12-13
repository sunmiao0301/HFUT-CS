//计科二班  孙淼   2018211958
#include <iostream>
using namespace std;
class point{
  public:
  	point(int x1,int y1):x(x1),y(y1){}
	point operator++(int);
	point operator++();
	point operator--(int);
	point operator--();
	void out(){cout<<"("<<x<<","<<y<<")"<<endl;}
  private:
  	int x,y;
}; 
  
point point::operator++(int){           
	x+=1;
	y+=1;
return *this;
}

point point::operator++(){
	x+=1;
	y+=1;
return *this;
}

point point::operator--(int){
	x-=1;
	y-=1;
return *this;
}

point point::operator--(){
	x-=1;
	y-=1;
return *this;
}

int main(){
	point p(3,4);
	p++;
	p.out();
	++p;
	p.out();
    p--;
    p.out();
	--p;
	p.out();
return 0;
}
/*
(4,5)
(5,6)
(4,5)
(3,4)

--------------------------------
Process exited after 2.311 seconds with return value 0
请按任意键继续. . .
*/
