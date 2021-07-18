#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<stack>
#include<set>
#include<cstring>
using namespace std;
map<char, int>getnum;		//构造map getnum
char get_char[100];         //获得对应字符（终结符和非终结符）的数组
vector<string>proce;		//存储产生式右部
int table[100][100];		 //预测分析表二维数组
int num = 0; int numvt = 0;     //numvt是终结符集合，0是‘#’，numvt为终结符首位，表空字
string first[100];
string follow[200];

void readin()
{
	memset(table, -1, sizeof(table));	//重置二维数组table
	getnum['#'] = 0;	//从#开始，即将对终结符入map
	get_char[0] = '#';
	cout << "请输入终结符集：" << endl;
	char x;
	do
	{
		cin >> x;
		getnum[x] = ++num;	//第一个输入的非终结符的索引为++num，即为1，对终结符入map
		get_char[num] = x;
	} while (cin.peek() != '\n');
	numvt = ++num;		//终结符开始入map
	getnum['@'] = numvt;        //空字
	get_char[num] = ('@');
	cout << "请输入非终结符集：" << endl;
	do
	{
		cin >> x;
		getnum[x] = ++num;	//终结符入map
		get_char[num] = x;
	} while (cin.peek() != '\n');
	cout << "输入所有产生式（空字用‘@’表示）,以end结束:" << endl;
	string pro;
	while (cin >> pro&&pro != "end")
	{
		string ss;//ss用于存储产生式并适时向向量proce压入产生式
		ss += pro[0];//先将产生式左部进入ss(proce)
		for (int i = 3; i<pro.size(); i++)//i=3用于跳过->
		{
			if (pro[i] == '|')
			{
				proce.push_back(ss);
				ss.clear(); 
				ss += pro[0];
			}
			else
			{
				ss += pro[i];
			}
		}
		proce.push_back(ss);
	}
}

void set_union(string &a, string b)  //取a,b并集赋值给a
{
	set<char>se;//set中无重复元素
	for (int i = 0; i<a.size(); i++)
		se.insert(a[i]);
	for (int i = 0; i<b.size(); i++)
		se.insert(b[i]);
	string ans;
	set<char>::iterator it;
	for (it = se.begin(); it != se.end(); it++)
		ans += *it;
	a = ans;
}

string get_f(int vn, int & has_0)     //如果产生式右部第一个字符为非终结符，求该非终结符的First集，将该非终结符的非@first集计入产生式左部的first集
{
	if (vn == numvt)	//如果终结符为空字
		has_0 = 1;
	if (vn<numvt)	//如果终结符不为空字，返回本身
		return first[vn];
	string ans;
	for (int i = 0; i<proce.size(); i++)
	{
		if (getnum[proce[i][0]] == vn)
			ans += get_f(getnum[proce[i][1]], has_0);//递归处理X->Y且Y->a或Y->@
	}
	return  ans;
}

void getfirst()
{
	for (int i = 1; i <= numvt; i++)     //如果A->α或A->@，则α或@加入firstA
	{
		first[i] += ('0' + i);
	}
	for (int j = 0; j<proce.size(); j++)    //扫描所有产生式，A->X1X2X3...Xk
	{
		int k = 0; int has_0 = 0;        //k扫描该产生式
		do {
			has_0 = 0;
			k++;
			if (k == proce[j].size())  //若已经到达产生式的最右部的非终结符（即右部的First集都含有空串），则将@加入左部的First集
			{
				first[getnum[proce[j][0]]] += ('0' + numvt);
				break;
			}                    
			set_union(first[getnum[proce[j][0]]], get_f(getnum[proce[j][k]], has_0));//否则把first(Yj)中的所有非@元素都加入first(x)中
		} while (has_0);  //到无法推出空字为止，停止遍历该产生式，进入下一个产生式
	}
}

void getfollow()
{
	set_union(follow[getnum[proce[0][0]]], "0");  //先添加‘#’到文法开始符号的follow集中
	for (int j = 0; j<proce.size(); j++)       //竖着扫所有产生式
	{
		for (int jj = 1; jj<proce[j].size(); jj++)   //横着扫所有产生式
		{
			if (getnum[proce[j][jj]] <= numvt)continue;  //遇到非终结符就跳过
			int k = jj; int has_0;
			do
			{
				has_0 = 0;
				k++;
				if (k == proce[j].size())   //若已经到达产生式末尾
				{
					set_union(follow[getnum[proce[j][jj]]], follow[getnum[proce[j][0]]]);//如果是A->αB，则将followA加入到followB
					break;
				}
				set_union(follow[getnum[proce[j][jj]]], get_f(getnum[proce[j][k]], has_0));//如果是A->αBβ...,则将firstβ\@加入followB
			} while (has_0);
		}
	}
}

void gettable()          //构造预测分析表：A->α，则放入[A,first(α)]   A->@,则放入[A,follow(A)]
{
	for (int i = 0; i<proce.size(); i++)   //扫所有产生式
	{
		if (proce[i][1] == '@')     //直接推出空字的，A->@,则放入[A,follow(A)]
		{
			string flw = follow[getnum[proce[i][0]]];
			for (int k = 0; k<flw.size(); k++)
			{
				table[getnum[proce[i][0]]][flw[k] - '0'] = i;
			}
		}
		string temps = first[getnum[proce[i][1]]];	//考察first集
		for (int j = 0; j<temps.size(); j++)               
		{

			if (temps[j] != ('0' + numvt))	//如果A->α且α不为@
			{
				table[getnum[proce[i][0]]][temps[j] - '0'] = i;//则产生式放入[A,first(α)] 
			}
			else                               //有空字的，考察的α的follow集
			{
				string flw = follow[getnum[proce[i][1]]];
				for (int k = 0; k<flw.size(); k++)
				{
					table[getnum[proce[i][0]]][flw[k] - '0'] = i;//则产生式放入[A,follow(α)] 
				}
			}
		}
	}
}

string get_proce(int i)  //获得proce内每个对应的产生式。
{
	if (i<0)return " ";    //无该产生式
	string ans;
	ans += proce[i][0];
	ans += "->";
	for (int j = 1; j<proce[i].size(); j++)
		ans += proce[i][j];
	return ans;
}

void print_first()
{
	cout << "first集如下:" << endl;
	for (int i = 1; i <= num; i++)
	{
		cout << "first [" << get_char[i] << "]: ";
		for (int j = 0; j<first[i].size(); j++)
			cout << get_char[first[i][j] - '0'] << " ";
		cout << endl;
	}
	cout << endl;
}

void print_follow()
{
	cout << "follow集如下：" << endl;
	for (int i = numvt + 1; i <= num; i++)
	{
		cout << "follow [" << get_char[i] << "]: ";
		for (int j = 0; j<follow[i].size(); j++)
			cout << get_char[follow[i][j] - '0'] << " ";
		cout << endl;
	}
	cout << endl;
}

void print_table()
{
	cout << "预测分析表如下：" << endl;
	for (int i = 0; i<numvt; i++)
		cout << '\t' << get_char[i];
	cout << endl;
	for (int i = numvt + 1; i <= num; i++)
	{
		cout << get_char[i];
		for (int j = 0; j<numvt; j++)
		{
			cout << '\t' << get_proce(table[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}

string word;
bool analyze()       //总控，分析字word的合法性，若合法，输出所有产生式。
{
	stack<char>sta;
	sta.push('#'); sta.push(proce[0][0]);
	int i = 0;
	while (!sta.empty())
	{
		int cur = sta.top();
		sta.pop();
		if (cur == word[i])       //是终结符，推进
		{
			i++;
		}
		else  if (cur == '#')   //成功，结束
		{
			return 1;
		}
		else  if (table[getnum[cur]][getnum[word[i]]] != -1) //查表
		{

			int k = table[getnum[cur]][getnum[word[i]]];
			cout << proce[k][0] << "->";
			for (int j = 1; j<proce[k].size(); j++)
				cout << proce[k][j];
			cout << endl;
			for (int j = proce[k].size() - 1; j>0; j--)  //逆序入栈
			{
				if (proce[k][j] != '@')
					sta.push(proce[k][j]);
			}
		}
		else      //失败！
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	readin();
	getfirst();
	getfollow();
	getfollow();
	gettable();
	print_first();
	print_follow();
	print_table();

	cout << "请输入字：" << endl;
	cin >> word;
	if (analyze())
		cout << "succeed!该字有效，所用产生式如上。" << endl;
	else   cout << "error!" << endl;

	cin.get();
	cin.get();
	return 0;
}
