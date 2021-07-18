//计算器
//李航 2018211966 
#include <iostream> 
#include <stack> 
using namespace std;  
const int maxlen = 100;//栈的最大存储量  
/*template <typename elementType>  
class stack {  
public:  
    stack();
    bool empty();
    bool full();
    bool get_top(elementType &x);
    bool push(elementType x);
    bool pop();  
private:  
    int count; 
    elementType data[maxlen]; 
};  
  
template <typename elementType>  
stack<elementType>::stack() {  
    count = 0;  
}  
  
template <typename elementType>  
bool stack<elementType>::empty() {  
    if (count == 0)  
        return true;  
    return false;  
}  
  
template <typename elementType>  
bool stack<elementType>::full() {  
    if (count == maxlen)  
        return true;  
    return false;  
}  
  
template <typename elementType>  
bool stack<elementType>::get_top(elementType &x) {  
    if (!empty()) {  
        x = data[count - 1];  
        return true;  
    }  
    return false;  
}  
  
template <typename elementType>  
bool stack<elementType>::push(elementType x) {  
    if (!full()) {  
        data[count++] = x;  
        return true;  
    }  
    return false;  
}  
  
template <typename elementType>  
bool stack<elementType>::pop() {  
    if (!empty()) {  
        --count;  
        return true;  
    }  
    return false;  
} */ 

//扫描数字的函数  
bool isnumber(char x) {  
    if (x >= '0' && x <= '9')  
        return true;  
    return false;  
}  
  
//判断运算符优先级的函数，通过数字大小来进行比较 
int priority(char x) {  
    if (x == '+' || x == '-')  
        return 0;  
    else if (x == '*' || x == '/')  
        return 1;  
    else if (x == '(' || x == ')')  
        return -1;  
    else if (x == '#')  
        return -2;  
}  
  
//运算的函数  
int calculate(string s) {  
    stack<int> number;  //数字栈 
    stack<char> operate;  //运算符栈 
    char top;  
    int a, b;  
    for (unsigned int i = 0; i < s.size(); ++i) {  
        if (isnumber(s[i])) {  
            int Temp = 0;  
            string temp;  
           temp += s[i];  
            while (isnumber(s[++i]))  
                temp += s[i]; 
            for (unsigned int j = 0; j < temp.size(); ++j) {  
                Temp = Temp * 10 + temp[j] - 48;  //char类型和int类型实现转换 
            }  
            number.push(Temp);    
        }//将字符数字转换成整形数字  
        if (!isnumber(s[i])) {  
            if (operate.empty()) {  
                operate.push(s[i]);  
            }//入栈第一个符号'#'  
            else {  
               top=operate.top();  
  
                if (priority(s[i])>priority(top) || s[i] == '(') {  
                    operate.push(s[i]);  
                }//入栈高优先级的运算符  
                else {  
                    while (priority(s[i]) <= priority(top)) {  
                        if (top == '#'&&s[i] == '#') {  
                            int answer;  
                            operate.pop();  
                            answer=number.top();   
                            cout << "\n答案是：" << answer << endl;  
                            number.pop();  
                            return 0;  
                        }//当运算符实现完全后，只剩下'#'  
                        else if (top == '('&&s[i] == ')') {  
                            ++i;  
                        }//当左右括号相遇时，跳过右括号，删除左括号  
                        else {  
                            a=number.top();   
                            number.pop();  
                            b=number.top();   
                            number.pop();  
                        }  
                        if (top == '+') {  
                            b += a;  
                            number.push(b);  
                        }  
                        else if (top == '-') {  
                            b -= a;  
                            number.push(b);  
                        }  
                        else if (top == '*') {  
                            b *= a;  
                            number.push(b);  
                        }  
                        else if (top == '/') {  
                            b /= a;  
                            number.push(b);  
                        }  
                        operate.pop();  
                        top=operate.top();//取前一个运算符，用于与现在扫描的运算符进行比较    
                    }//将优先级高的运算符实现计算  
                    operate.push(s[i]);//用于当top=='#'时，将最后一个运算符入栈  
                }  
            }  
        }//扫描运算符，并判断优先级，以及运算  
    }//主循环  
}//对运算符的扫描，和数字字符的转化，以及计算  
  
int main() {  
    string expression;  
    cout << "输入一个用'#'开头和结尾的表达式：" << endl;  
    cin >> expression;  
    calculate(expression);  
    cin.get(), cin.get();  
}
 
