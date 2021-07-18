#ifndef _LR_
#define _LR_
#include <string>
using namespace std;

class Grammar {
public:
	//产生式的个数
	int grammarNum;
	//定义产生式数组
	string formula[100] = { " ","E->E+T","E->T","T->T*F","T->F","F->(E)","F->i" };

	Grammar() {
		grammarNum = 6;
	}
};
//定义LR文法的分析表
class LRAnalyseTable {
public:
	char terminalChar[100] = { 'i','+','*','(',')','#' };
	//定义终结符的个数
	int terNum = 6;
	char nonTerminalChar[100] = { 'E','T','F' };
	//定义非终结符的个数
	int nonTerNum = 3;
	//定义状态数
	int statusNum = 12;
	string action[12][6] = { { "s5","","","s4","","" },{ "","s6","","","","acc" },{ "","r2","s7","","r2","r2" },{ "","r4","r4","","r4","r4" },{ "s5","","","s4","","" },{ "","r6","r6","","r6","r6" },{ "s5","","","s4","","" }
	,{ "s5","","","s4","","" },{ "","s6","","","s11","" },{ "","r1","s7","","r1","r1" },{ "","r3","r3","","r3","r3" },{ "","r5","r5","","r5","r5" } };
	int goTo[12][3] = { { 1,2,3 },{ -1,-1,-1 },{ -1,-1,-1 },{ -1,-1,-1 },{ 8,2,3 },{ -1,-1,-1 },{ -1,9,3 },{ -1,-1,10 },{ -1,-1,-1 },{ -1,-1,-1 },{ -1,-1,-1 },{ -1,-1,-1 } };
	//获取终结符的索引
	int getTerminalIndex(char var) {
		for (int i = 0; i<terNum; i++) {
			if (terminalChar[i] == var) {
				return i;
			}
		}
		return -1;
	}
	//获取非终结符的索引
	int getNonTerminalIndex(char var) {
		for (int i = 0; i<nonTerNum; i++) {
			if (nonTerminalChar[i] == var) {
				return i;
			}
		}
		return -1;
	}
};

#endif 