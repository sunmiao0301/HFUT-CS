#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct node
{
	char data;
	node *f_s;
	node *n_b;
};
class bitree
{
public:
	~bitree();
	node * creat();
	int high(node *T);
	void destroy_node(node *dnode);
	void cengcibianli(node *T);
private:
	node *root;
};
bitree::~bitree()
{
	destroy_node(root);
}
void bitree::destroy_node(node *dnode)
{
24	if (dnode == NULL)
		return;
	destroy_node(dnode->f_s);
	destroy_node(dnode->n_b);
	delete dnode;
}
node * bitree::creat()
{
	char a;
	cin >> a;
	if (a == '*')
		return NULL;
	node *p = new node;
	p->data = a;
	p->f_s = creat();
	p->n_b = creat();
	return p;
}
int bitree::high(node *T)
{
	int h;
	if (T == NULL)
		return 0;
	h = max(high(T->f_s), high(T->n_b)) + 1;
	return h;
}

void bitree::cengcibianli(node *T)
{
	node *item;`11Q`
	q.push(T);
	while (!q.empty())
	{
		item = q.front();
		cout << item->data;
		q.pop();
		if (item->f_s != 0)
		{
			q.push(item->f_s);
			item = item->f_s;

			while (item->n_b != 0)
			{
				q.push(item->n_b);
				item = item->n_b;
			}
		}
	}
}

int main()
{
	bitree b;
	node *root1;
	root1 = b.creat();
	b.cengcibianli(root1);
	b.~bitree();
	getchar();
	getchar();
}