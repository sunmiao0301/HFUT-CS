#include <iostream>
using namespace std;
const int max_vex_node = 20;
const int max_edge = 40;
const int max_weight = 50;
typedef struct edge_node
{//边表结点的定义  
	int adjvex;//存放邻接点在顶点表中的位置  
	struct edge_node *nextarc;//指向下一个边表结点  
	int weight;
}edge_node;

typedef struct vex_node
{//顶点表结点的定义   
	char vex;//存放顶点信息  
	edge_node * firstarc;//指向第一个边表结点  
}vex_node;
class graph {
public:
	graph() {};
	int creat();
	int path_all1(int u, int v, int path[max_edge], int i);//i初始为0
	int path_all2(int u, int v, int k, int path[max_edge], int d);//d初始为-1
	int visited[max_edge];
	int path[max_edge];
	int chushi();
private:
	int n, e;
	vex_node adjlist[max_vex_node];
};

int graph::creat() {
	int i,j, k;
	cout << "请输入顶点数和边数" <<endl;

	cin >> n >> e;
	for (int i = 0; i < n; i++) {
		adjlist[i].vex = i;
		adjlist[i].firstarc = NULL;
	}
	cout << "输入边之间的关系" << endl;
	for (i = 0; i < e; i++) {

		cin >> j >> k;//依次输入弧的相关信息
		edge_node *p = new edge_node;
		p->adjvex = k;

		p->nextarc = adjlist[j].firstarc;//把P插入到链表中
		adjlist[j].firstarc = p;
	}
	return 1;
}
int graph::chushi() {

	for (int i = 0; i < max_vex_node; i++)
	{
		visited[i] = 0;
	}
	return 1;

}

int graph::path_all1(int u, int v, int path[], int i) {//输出从u到v的所有简单路径
	edge_node *p;
	int n;
	visited[u] = 1;
	p = adjlist[u].firstarc;


	while (p) {

		n = p->adjvex;
		if (n == v) {
			path[i + 1] = v;
			for (int j = 0; j <= i + 1; j++)
				cout << path[j] << " ";
			cout << endl;
		}
		else if (visited[n] == 0) {
			path[i + 1] = n;
			path_all1(n, v, path, i + 1);
		}
		p = p->nextarc;
	}
	visited[u] = 0;
	return 1;
}
int graph::path_all2(int u, int v, int k, int path[], int d) {//输出从u到v所有路径长度为k的路径
	int m;
	edge_node *p;
	visited[u] = 1;

	d++;
	path[d] = u;
	if (u == v && d == k) {
		for (int i = 0; i <= d; i++)
			cout << path[i] << " ";
		cout << endl;
	}
	p = adjlist[u].firstarc;
	while (p) {


		m = p->adjvex;
		if (visited[m] == 0) {
			path_all2(m, v, k, path, d);
		}
		p = p->nextarc;

	}
	visited[u] = 0;
	return 1;
}
int main() {
	cout << "依次输入一个起点，一个终点，一个路径长度" << endl;
	int u, v, k, d = -1, i = 0;
	cin >> u >> v >> k;
	graph t;
	t.path[0] = u;
	t.creat();
	t.chushi();
	cout << "该图的所有简单路径" << endl;
	t.path_all1(u, v, t.path, i);
	t.chushi();
	cout << "该图的所有路径长度为" << k << "的路径" << endl;
	t.path_all2(u, v, k, t.path, d);
}
