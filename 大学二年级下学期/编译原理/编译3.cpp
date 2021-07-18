#include <iostream>
using namespace std;
const int MaxLen = 20;
const int Length = 20;
char ch, Y;
char strToken[Length];

bool flag = true;
int point = 0, step = 1;


class stack//栈的构造及初始化
{
public:
	stack();
	bool empty()const;//判断空
	bool full()const;//判断满
	bool get_top(char &c)const;//取栈顶元素
	bool push(const char c);//进栈
	bool pop();//出栈
	void out();//输出栈中元素
	void outl();
	~stack() {};//析构函数
private:
	int count;//栈长度
	char data[MaxLen];//栈中元素
};

stack l, r;//l为符号栈，r为状态栈

stack::stack() {
	count = 0;
}

bool stack::empty() const {
	if (count == 0)
		return 1;
	return 0;
}

bool stack::full() const {
	if (count == MaxLen)
		return 1;
	return 0;
}

bool stack::get_top(char &c)const {
	if (empty())
		return 1;
	else {
		c = data[count - 1];
		return 0;
	}
}

bool stack::push(const char c) {
	if (full())
		return 1;
	else {
		data[count++] = c;//count先被用于data 然后++
		return 0;
	}
}

bool stack::pop() {
	if (empty())
		return 1;
	count--;
	return 0;
}
void stack::out() {
	for (int i = 0; i<count; i++)
		cout << data[i];
	cout << '\t';
}

void stack::outl() {
	for (int i = 0; i<count; i++)
		cout << int(data[i]);
	cout << '\t';
}
void print(int i, char *c) {
	for (int j = i; j<Length; j++)
		cout << c[j];
	cout << '\t';
}

void Goto(int i, char c) {
	if (i == 0) {
		if (c == 'E') {
			r.push(1);
			cout << ",GOTO(0,E)=1 入栈" << endl;
		}
		else if (c == 'T') {
			r.push(2);
			cout << ",GOTO(0,T)=2 入栈" << endl;
		}
		else if (c == 'F') {
			r.push(3);
			cout << ",GOTO(0,F)=3 入栈" << endl;
		}
		else
			flag = false;
	}
	else if (i == 4) {
		if (c == 'E') {
			r.push(8);
			cout << ",GOTO(4,E)=8 入栈" << endl;
		}
		else if (c == 'T') {
			r.push(2);
			cout << ",GOTO(4,T)=2 入栈" << endl;
		}
		else if (c == 'F') {
			r.push(3);
			cout << ",GOTO(4,F)=3 入栈" << endl;
		}
		else
			flag = false;
	}
	else if (i == 6) {
		if (c == 'T') {
			r.push(9);
			cout << ",GOTO(6,T)=9 入栈" << endl;
		}
		else if (c == 'F') {
			r.push(3);
			cout << ",GOTO(6,F)=3 入栈" << endl;
		}
		else
			flag = false;
	}
	else if (i == 7) {
		if (c == 'F') {
			r.push(10);
			cout << ",GOTO(7,F)=10 入栈" << endl;
		}
		else
			flag = false;
	}
	else
		flag = false;
}

void Action0() {
	if (ch == 'i') {
		cout << step++ << '\t';
		r.outl();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[0,i]=S5,状态5入栈" << endl;
		r.push(5);
		l.push(ch);
		ch = strToken[point++];
	}
	else if (ch == '(') {
		cout << step++ << '\t';
		r.outl();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[0,(]=S4,状态4入栈" << endl;
		r.push(4);
		l.push(ch);
		ch = strToken[point++];
	}
	else
		flag = false;
}

void Action1() {
	if (ch == '+') {
		cout << step++ << '\t';
		r.outl();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[1,+]=S6,状态6入栈" << endl;
		r.push(6);
		l.push(ch);
		ch = strToken[point++];
	}
	else if (ch == '#') {
		flag = false;
		cout << step++ << '\t';
		r.outl();
		l.out();
		print(point - 1, strToken);
		cout << "Acc:分析成功" << endl;
	}
	else
		flag = false;
}

void Action2() {
	if (ch == '*') {
		cout << step++ << '\t';
		r.outl();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[2,*]=S7,状态7入栈" << endl;
		r.push(7);
		l.push(ch);
		ch = strToken[point++];
	}
	else if ((ch == '+') || (ch == ')') || (ch == '#')) {
		cout << step++ << '\t';
		r.outl();
		l.out();
		l.pop();
		l.push('E');
		print(point - 1, strToken);
		cout << "r2:E->T归约";
		r.pop();
		r.get_top(Y);
		Goto(int(Y), 'E');
	}
	else
		flag = false;
}

void Action3() {
	if ((ch == '+') || (ch == '*') || (ch == ')') || (ch == '#')) {
		cout << step++ << '\t';
		r.outl();
		l.out();
		l.pop();
		l.push('T');
		print(point - 1, strToken);
		cout << "r4:T->F归约";
		r.pop();
		r.get_top(Y);
		Goto(int(Y), 'T');
	}
	else
		flag = false;
}

void Action4_6_7(int x) {
	if (ch == 'i') {
		cout << step++ << '\t';
		r.outl();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[";
		cout << x << ",i]=S5,状态5入栈" << endl;//???
		r.push(5);
		l.push(ch);
		ch = strToken[point++];
	}
	else if (ch == '(') {
		cout << step++ << '\t';
		r.outl();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[";
		cout << x << ",(]=S4,状态4入栈" << endl;
		r.push(4);
		l.push(ch);
		ch = strToken[point++];
	}
	else
		flag = false;
}

void Action5() {
	if ((ch == '+') || (ch == '*') || (ch == ')') || (ch == '#')) {
		cout << step++ << '\t';
		r.outl();
		l.out();
		l.pop();
		l.push('F');
		print(point - 1, strToken);
		cout << "r6:F->i归约";
		r.pop();
		r.get_top(Y);
		Goto(int(Y), 'F');
	}
	else
		flag = false;
}

void Action8() {
	if (ch == '+') {
		cout << step++ << '\t';
		r.outl();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[8,+]=S6,状态6入栈" << endl;
		r.push(6);
		l.push(ch);
		ch = strToken[point++];
	}
	else if (ch == ')') {
		cout << step++ << '\t';
		r.outl();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[8,)]=S11,状态11入栈" << endl;
		r.push(11);
		l.push(ch);
		ch = strToken[point++];
	}
	else
		flag = false;
}

void Action9() {
	if (ch == '*') {
		cout << step++ << '\t';
		r.outl();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[9,*]=S7,状态7入栈" << endl;
		r.push(7);
		l.push(ch);
		ch = strToken[point++];
	}
	else if ((ch == '+') || (ch == ')') || (ch == '#')) {
		cout << step++ << '\t';
		r.outl();
		l.out();
		l.pop();
		l.pop();
		l.pop();
		l.push('E');
		print(point - 1, strToken);
		cout << "r1:E->E+T归约";
		r.pop();
		r.pop();
		r.pop();
		r.get_top(Y);
		Goto(int(Y), 'E');
	}
	else
		flag = false;
}

void Action10() {
	if ((ch == '+') || (ch == '*') || (ch == ')') || (ch == '#')) {
		cout << step++ << '\t';
		r.outl();
		l.out();
		l.pop();
		l.pop();
		l.pop();
		l.push('T');
		print(point - 1, strToken);
		cout << "r3:T->T*F归约";
		r.pop();
		r.pop();
		r.pop();
		r.get_top(Y);
		Goto(int(Y), 'T');
	}
	else
		flag = false;
}

void Action11() {
	if ((ch == '+') || (ch == '*') || (ch == ')') || (ch == '#')) {
		cout << step++ << '\t';
		r.outl();
		l.out();
		l.pop();
		l.pop();
		l.pop();
		l.push('F');
		print(point - 1, strToken);
		cout << "r5:F->(E)归约";
		r.pop();
		r.pop();
		r.pop();
		r.get_top(Y);
		Goto(int(Y), 'F');
	}
	else
		flag = false;
}

void run() {
	cout << "输入待处理字符串" << endl;
	cin >> strToken;
	cout << "步骤\t" << "状态栈\t" << "符号栈\t" << "输入串\t\t" << "动作说明" << endl;
	ch = strToken[point++];
	l.push('#');
	r.push(0);
	r.get_top(Y);
	while (flag) {
		if (int(Y) == 0)
			Action0();
		else if (int(Y) == 1)
			Action1();
		else if (int(Y) == 2)
			Action2();
		else if (int(Y) == 3)
			Action3();
		else if ((int(Y) == 4) || (int(Y) == 6) || (int(Y) == 7))
			Action4_6_7(int(Y));
		else if (int(Y) == 5)
			Action5();
		else if (int(Y) == 8)
			Action8();
		else if (int(Y) == 9)
			Action9();
		else if (int(Y) == 10)
			Action10();
		else if (int(Y) == 11)
			Action11();
		else
			flag = false;
		r.get_top(Y);
	}
}
int main() {
	run();
	cin.get();
	cin.get();
	return 0;
}

