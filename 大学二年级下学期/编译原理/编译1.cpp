#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string key[8] = { "do","end","for","if","printf","scanf","then","while" };
string separator[6] = { ",",";","(",")","{","}" };
string optr[4] = {"+","-","*","/"};
char ch;

bool IsKey(string s) {//判断是否为关键字
	int i;
	for (i = 0; i < 8; i++)
		if (!strcmp(key[i].c_str(), s.c_str()))
			return 1;
		return 0;
}

bool IsSeparator(string s) {//判断是否为分界符
	int i;
	for (i = 0; i < 6; i++)
		if (!strcmp(separator[i].c_str(), s.c_str()))
			return 1;
		return 0;
}

bool IsOptr(string s) {//判断是否为运算符
	int i;
	for (i = 0; i < 4; i++)
		if (!strcmp(optr[i].c_str(), s.c_str()))
			return 1;
		return 0;
}

bool IsLetter(char ch) {//判断是否为字母
	if (((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')))
		return 1;
	return 0;
}

bool IsDigit(char ch) {//判断是否为数字
	if (ch >= '0'&&ch <= '9')
		return 1;
	return 0;
}

void analyse(ifstream &in) {
	string s = "";//对这个函数来说，是全局
	char ch;
	int line = 1, row = 0;
	while ((in.get(ch))) {
		s = "";//对这个循环来说，是全局
		if ((ch == ' ' || ch == '\t')) {}//去掉空格和制表符
		else if (ch == '\n') {line++, row = 0;}//处理换行符
		else if (IsLetter(ch)) { //处理字母开头
			row++;
			while (IsLetter(ch) || IsDigit(ch)) {//连接数字就是标识符（6类）
				s = s + ch;
				ch = in.get();//in.get(c)与c = in.get()不同
			}
			in.seekg(-1, ios::cur);//为下一个判断做准备
			if (IsKey(s))//判断上面的s是关键字还是标识符
				cout << s << "\t(" << 1 << "," << s << ")\t" << "\t关键字" << "\t" << "\t" << "(" << line << "," << row << ")" << endl;//
			else
				cout << s <<" \t(" << 6 << "," << s << ")\t" << "\t标识符" << "\t" << "\t" << "(" << line << "," << row << ")" << endl;//
		}
		else if (IsDigit(ch)) {//处理数字开头
			row++;
			while (IsLetter(ch)) {
					s = s + ch;
					ch = in.get();
				
				in.seekg(-1, ios::cur);
				cout << s << "\tError" << "\t" << "\tError" << "\t" << "\t(" << line << "," << row << ")" << endl;
				while (IsDigit(ch)) {//连续的数字还是常数
					s = s + ch;
					ch = in.get();
				}
				in.seekg(-1, ios::cur);
				cout << s << "\t(" << 5 << "," << s << ")\t" << "\t常数" << "\t" << "\t" << "(" << line << "," << row << ")" << endl;
			}
		}
		else {//与51行对应（为什么in,get(c)也能返回0？
			s = "";//清空string s
			string s1 = "";//
			s = s + ch;
			if (IsOptr(s)) {//处理算数运算符开头
				row++;
				ch = in.get();
				s1 = s1 + ch;
				if (IsOptr(s1)) {//连续两个算数运算符是Error，输出s1
					s = s + s1;
					cout << s << "\tError" << "\t" << "\tError" << "\t" << "\t(" << line << "," << row << ")" << endl;
				}
				else{//否则后撤一格并输出s
					in.seekg(-1, ios::cur);
					cout << s << "\t(" << 3 << "," << s << ")\t" << "\t算数运算符" << "\t" << "(" << line << "," << row << ")" << endl;//
				}						
			}
			else if (IsSeparator(s)) {//处理分隔符
				row++;
				cout << s << "\t(" << 2 << "," << s << ")\t" << "\t分界符" << "\t" << "\t" << "(" << line << "," << row << ")" << endl;//
			}
			else {//处理关系运算符（如果后面有else（不带if的else），则只要前面的if和else if都没执行，就执行最后一个else。）
				switch (ch) {
					row++;
				case'=': {
					row++;
					cout << "=" << "\t(" << 4 << "," << "=" << ")\t" << "\t关系运算符" << "\t" << "(" << line << "," << row << ")" << endl;
				}break;
				case'>': {
					row++;
					ch = in.get();//不等价与in.get(ch)
					if(ch=='=')
						cout << ">=" << "\t(" << 4 << "," << ">=" << ")\t" << "\t关系运算符" << "\t" << "(" << line << "," << row << ")" << endl;
					else {
						cout << ">" << "\t(" << 4 << "," << ">" << ")\t" << "\t关系运算符" << "\t" << "(" << line << "," << row << ")" << endl;
					}
				}break;
				case'<': {
					row++;
					ch = in.get();
					if(ch=='=')
						cout << "<=" << "\t(" << 4 << "," << "<=" << ")\t" << "\t关系运算符" << "\t" << "(" << line << "," << row << ")" << endl;
					else if(ch=='>')
						cout << "<>" << "\t(" << 4 << "," << "<>" << ")\t" << "\t关系运算符" << "\t" << "(" << line << "," << row << ")" << endl;
				}break;
				default: {
					row++;
					cout << ch << "\tError" << "\t" << "\tError" << "\t" << "\t("  << line << "," << row << ")" << endl;
				}
				}
			}
		}
	}
}

int main() {
	ifstream in;
	in.open("D:\\大学作业\\大二下学期作业\\编译原理\\实验\\bianyi1.txt", ios::in);
	if (in.is_open()) {
		analyse(in);
		in.close();
	}
	else
		cout << "无法读取文件" << endl;
		cin.get();
		cin.get();
	return 0;
}