#include<iostream>
  
#include <string>

using namespace std;
const int MaxLen = 20;//初始化栈最大长度
const int Length = 20;//初始化数组最大长度

char Vn[5] = { 'E','G','T','S','F' };//非终结符数组
char Vt[8] = { 'i','(',')','+','-','*','/','#' };//终结符数组

char ch, X;//ch用于读取当前字符，X用于获取栈顶元素
char strToken[Length];//存储待分析表达式（数组存储

struct LL//
{
	char*c;
};
LL E[8] = { "TG","TG","error","error","error","error","error","error" };
LL G[8] = { "error","error","null","+TG","-TG","error","error","null" };
LL T[8] = { "FS","FS","error","error","error","error","error","error" };
LL S[8] = { "error","error","null","null","null","*FS","/FS","null" };
LL F[8] = { "i","(E)","error","error","error","error","error","error" };

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
	~stack() {};//析构函数
private:
	int count;//栈长度
	char data[MaxLen];//栈中元素
};

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
		c =data[count - 1];
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
	for (int i = 0; i < count; i++)
		cout << data[i];
	cout << '\t';
}

int length(char *c) {
	int l = 0;
	for (int i = 0; c[i] != '\0'; i++)//！='0'即运行到字符串结尾处结束
		l++;
	return l;
}


void print(int i, char *c) {
	for (int j = i; j < Length; j++)
		cout << c[j];
	cout << '\t'; //这个制表符只输出一次啊
}

void run() {
	bool flag = true;//循环条件?
	int step = 0, point = 0;//步骤，指针
	int len;//长度
	cout << "输出要分析的符号串：" << endl;
	cin >> strToken;
	ch = strToken[point++];
	stack s;
	s.push('#');
	s.push('E');
	s.get_top(X);
	cout << "步骤\t" << "分析栈\t" << "剩余输入串\t\t" << "所用产生式\t" << "动作" << endl;
	cout << step++ << '\t';
	s.out();
	print(point - 1, strToken);
	cout << '\t' << "初始化" << endl;
	while (flag) {
		if ((X == Vt[0]) || (X == Vt[1]) || (X == Vt[2]) || (X == Vt[3]) || (X == Vt[4]) || (X == Vt[5]) || (X == Vt[6])) {//终结符匹配
			if (X == ch) {
				s.pop();
				s.get_top(X);
				ch = strToken[point++];
				cout << step++ << '\t';
				s.out();
				print(point - 1, strToken);
				cout << '\t' << "\tGETNEXT(l)" << endl;
			}
			else {
				flag = false;
			}
		}
		else if (X == '#') {//分析成功，停止分析	
			if (X == ch) {
				cout << step++ << '\t';
				s.out();
				print(point - 1, strToken);
				cout << '\t'<< X << "->" << ch << '\t'  << "\t结束" << endl;
				s.pop();
				flag = false;
			}
			else {
				flag = false;
			}
		}
		else if (X == Vn[0]) {
			for (int i = 0; i < 8; i++)
				if (ch == Vt[i]) {
					if (E[i].c=="error") {
						flag = false;
					}
					else {
						s.pop();
						len = length(E[i].c) - 1;
						for (int j = len; j >= 0; j--)
							s.push(E[i].c[j]);
						cout << step++ << '\t';
						s.out();
						print(point - 1, strToken);
						cout << X << "->" << E[i].c << '\t' << "\tPOP,PUSH(";
						for (int j = len; j >= 0; j--)
							cout << E[i].c[j];
						cout << ")" << endl;
						s.get_top(X);
					}
				}
		}
		else if (X == Vn[1]) {
			for (int i = 0; i < 8; i++)
				if (ch == Vt[i]) {
					if (strcmp(G[i].c, "null") == 0) {
						s.pop();
						cout << step++ << '\t';
						s.out();
						print(point - 1, strToken);
						cout << X << "->" << "ε" << '\t' << "\tPOP" << endl;
						s.get_top(X);
					}
					else if (strcmp(G[i].c, "error") == 0) {
						flag = false;
					}
					else {
						s.pop();
						len = length(G[i].c) - 1;
						for (int j = len; j >= 0; j--)
							s.push(G[i].c[j]);
						cout << step++ << '\t';
						s.out();
						print(point - 1, strToken);
						cout << X << "->" << G[i].c << '\t' << "\tPOP.PUSH(";
						for (int j = len; j >= 0; j--)
							cout << G[i].c[j];
						cout << ")" << endl;
						s.get_top(X);
					}
				}
		}
		else if (X == Vn[2]) {
			for (int i = 0; i < 8; i++)
				if (ch == Vt[i]) {
					if (strcmp(T[i].c, "error") == 0) {
						flag = false;
					}
					else {
						s.pop();
						len = length(T[i].c) - 1;
						for (int j = len; j >= 0; j--)
							s.push(T[i].c[j]);
						cout << step++ << '\t';
						s.out();
						print(point - 1, strToken);
						cout << X << "->" << T[i].c << '\t' << "\tPOP.PUSH(";
						for (int j = len; j >= 0; j--)
							cout << T[i].c[j];
						cout << ")" << endl;
						s.get_top(X);
					}
				}
		}
		else if (X == Vn[3]) {
			for (int i = 0; i < 8; i++)
				if (ch == Vt[i]) {
					if (strcmp(S[i].c, "null") == 0) {
						s.pop();
						cout << step++ << '\t';
						s.out();
						print(point - 1, strToken);
						cout << X << "->" << "ε" << '\t' << "\tPOP" << endl;
						s.get_top(X);
					}
					else if (strcmp(S[i].c, "error") == 0) {
						flag = false;
					}
					else {
						s.pop();
						len = length(S[i].c) - 1;
						for (int j = len; j >= 0; j--)
							s.push(S[i].c[j]);
						cout << step++ << '\t';
						s.out();
						print(point - 1, strToken);
						cout << X << "->" << S[i].c << '\t' << "\tPOP.PUSH(";
						for (int j = len; j >= 0; j--)
							cout << S[i].c[j];
						cout << ")" << endl;
						s.get_top(X);
					}
				}
		}
		else if (X == Vn[4]) {
			for (int i = 0; i < 7; i++)
				if (ch == Vt[i]) {
					if (strcmp(F[i].c, "error") == 0) {
						flag = false;
					}
					else {
						s.pop();
						len = length(F[i].c) - 1;
						for (int j = len; j >= 0; j--)
							s.push(F[i].c[j]);
						cout << step++ << '\t';
						s.out();
						print(point - 1, strToken);
						cout << X << "->" << F[i].c << '\t' << "\tPOP,PUSH(";
						for (int j = len; j >= 0; j--)
							cout << F[i].c[j];
						cout << ")" << endl;
						s.get_top(X);
					}
				}
		}
		else {//出错处理
			flag = false;
		}
	}
}
int main() {
	run();
	system("pause");
	return 0;
}