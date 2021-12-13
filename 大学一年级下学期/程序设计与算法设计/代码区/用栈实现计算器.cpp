#ifndef STACK_H
#define STACK_H    
#include <iostream>  
using namespace std;    
const int maxlen = 100;
template <typename elementType>  
class stack 
{
public:
	stack();//初始化
	bool empty();//判断空
	bool full();//判断满
	bool get_top(elementType &x);//取栈顶元素
	bool push(elementType x);//入栈
	bool pop();//出栈
private:
	int count;
	elementType data[maxlen];
};
template <typename elementType>
stack<elementType>::stack()
{
	count = 0;
}
template <typename elementType>
bool stack<elementType>::empty() 
{
	if (count == 0)
		return true;
	return false;
}
template <typename elementType>
bool stack<elementType>::full() 
{
	if (count == maxlen)
		return true;
	return false;
}
template <typename elementType> 
bool stack<elementType>::get_top(elementType &x) 
{ 
	if (!empty()) 
	{ 
		x = data[count - 1];          
	    return true; 
	}     
	return false;
}
template <typename elementType> 
bool stack<elementType>::push(elementType x) 
{ 
	if (!full()) 
	{
		data[count++] = x;
		return true; 
	}      
	return false; 
}
template <typename elementType>  
bool stack<elementType>::pop() 
{ 
	if (!empty()) 
	{ 
		--count;          
		return true; 
	}      
	return false; 
}
#endif
#include <iostream>  
#include <cctype>
#include <string>
#include <cstring>
/*#include <cstack>*/
using namespace std;
    int priority(char x)
	{
		if (x == '+' || x == '-')
			return 0;
		else if (x == '*' || x == '/')
			return 1;
		else if (x == '(' || x == ')')
			return -1;
		else if (x == '#')
			return -2;
	}
	int calculate(string s)
	{
		stack<int> number;
		stack<char> operate;
		char top;
		int a, b;
		for (unsigned int i = 0; i < s.size(); ++i)
		{
			if (isdigit(s[i]))
			{
				int Temp = 0;
				string temp;
				temp += s[i];
				while (isdigit(s[++i]))
					temp += s[i];
				for (unsigned int j = 0; j < temp.size(); ++j)
				{
					Temp = Temp * 10 + temp[j] - 48;
				}
				number.push(Temp);
				temp.clear();
			}//将字符数字转换成整形数字
			if (!isdigit(s[i]))
			{
				if (operate.empty())
				{
					operate.push(s[i]);
				}//入栈第一个符号'#'
				else
				{
					operate.get_top(top);
					if (priority(s[i]) > priority(top) || s[i] == '(')
					{
						operate.push(s[i]);
					}//入栈高优先级的运算符
					else
					{
						while (priority(s[i]) <= priority(top))
						{
							if (top == '#'&&s[i] == '#')
							{
								int answer;
								operate.pop();
								number.get_top(answer);
								cout << "\n答案是：" << answer << endl;
								number.pop();
								return 0;
							}//当运算符实现完全后，只剩下'#'                          
							else if (top == '('&&s[i] == ')')
							{
								++i;
							}//当左右括号相遇时，跳过右括号，删除左括号
							else
							{
								number.get_top(a);
								number.pop();
								number.get_top(b);
								number.pop();
							}
							if (top == '+')
							{
								b += a;
								number.push(b);
							}
							else if (top == '-')
							{
								b -= a;
								number.push(b);
							}
							else if (top == '*')
							{
								b *= a;
								number.push(b);
							}
							else if (top == '/')
							{
								b /= a;
								number.push(b);
							}
							operate.pop();
							operate.get_top(top);
						}
						operate.push(s[i]);
					}
				}
			}
		}
	}
	int main()
	{
		string expression;
		cout << "输入一个用'#'开头和结尾的表达式：" << endl;
		getline(cin, expression);
		calculate(expression);
		cin.get();
		cin.get();
	}
	