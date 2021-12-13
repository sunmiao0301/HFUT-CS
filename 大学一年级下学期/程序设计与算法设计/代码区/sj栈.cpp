#include <iostream>
using namespace std;
class stack
{
public://函数成员应为公有成员
	stack();
	bool empty()const;//由于这一判断函数的求解过程不会改变栈本身各分量的内容，因此，可在函数头的后面加上const来描述。//且声明时有const，则定义时也应有const
	bool full()const;
	int get_top(int &x)const;//对引用的理解:
	int push(const int x);
	int pop();
private://数据成员应为私有成员
	int count;
	int data[100];
};
stack::stack() { count = 0; }
bool stack::empty()const { if (count == 0) return true; return false; }
bool stack::full()const { if (count == 100)return true; return false; }
int stack::get_top(int &x)const
{
	if (count==0)//牢记判断语句(==)不同于赋值语句(=)
		return -1;
	else
	{
		x = data[count - 1];
		return 1;
	}
}
int stack::push(const int x)
{
	if (full())return -1;
	data[count] = x;
	count++;
	return 0;
}
int stack::pop()
{
	if (empty())return -1;
	count--;
	return 0;
}
