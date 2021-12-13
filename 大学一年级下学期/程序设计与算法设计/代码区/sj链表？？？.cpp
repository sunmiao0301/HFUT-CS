#include <iostream>
using namespace std;
struct node {
	int data;
	node *next;//*next是链表节点指向下一个节点的指针，用来存放下一个节点的地址域，这是链表的一种固定结构 
};
class list {
public:
	list();
	~list();
	int length()const;//const用在成员函数后，主要是针对类的const对象，const修饰说明它是一个常量，它的值是不能被修改的。没有什么地方是必须要用的，你只要觉得这个数字你不会改变就可以用。一般在函数传递参数中用的比较多，这么做是为了防止你在函数中对不应该在这里改变的量不小心进行了改变。这样的函数叫常成员函数。常成员函数可以理解为是一个“只读”函数，它既不能更改数据成员的值，也不能调用那些能引起数据成员值变化的成员函数，只能调用const成员函数。
	vo  id create(int n);
	int get(const int i, int &x)const;//此处const在函数内参数前也存在，其作用比如你要求某个int的平方，写一个square函数int square（ const int& a ）{ return a*a; }这个写法中没有修改a的值，因此正确但若写成int square（ const int& a ）{ a=a*a; return a;}则程序会报错啦。因为你修改了a的值，这是const所不允许的。						  
	int insert(const int i, const int x)
	int delete_data(const int i);
	void print();
	node *findk(node *head, int k);
	node *& get_ptr(int pos);
	int count;
	node *head;
};
list::list() {
	head = new node;
	head->next = NULL;
	count = 0;
}
void list::create(int n) {//分清楚p与p->next区别，分清指针与结点区别是理解下面代码的关键。。。p是指针，指向p所指的结点，p->next是p所指的结点的下一个结点
	int x; int y = 1;
	cin >> x;
	node *rear = head;
	while (y != n) {
		count++;
		node *s = new node;
		s->data = x;
		rear->next = s;
		rear = s;
		rear->next = NULL;
		cin >> x;
		y++;
	}
}
int list::length()const {
	node *p = head->next;
	int n = 0;
	while (p != NULL) {
		n++;
		p = p->next;
	}
	return n;
}
int list::get(const int i, int &x)const {//此处引用的作用？？？？？？？
	node*p;
	p = head->next;
	int j = 1;
	while (p != NULL && j != i) {
		p = p->next;
		j++;
	}
	if (p == NULL) {
		cout << "error" << endl;
		return 0;
	}
	x = p->data;
	return 1;
}
int list::insert(const int i, const int x) {
	node *p;
	p = head;
	int j = 0;
	while (p != NULL && j != i) {
		p = p->next; j++;
	}
	if (i<1 || i>count + 1) {
		cout << "error" << endl;
		return 0;
	}
	node *s = new node;
	s->data = x;
	s->next = p->next;
	p->next = s;
	count++;
	return 1;
}
int list::delete_data(const int i) {
	node *p; node *u;
	p = head;
	int j = 0;
	while (p != NULL && j != i) {
		p = p->next; j++;
	}
	if (i<1 || i>count + 1) {
		cout << "error" << endl;
		return 0;
	}
	u = p->next;
	p->next = u->next;
	delete u;
	count--;
	return 1;
}
void list::print() {
	node *p = head->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
}
list::~list() {
	for (int i = 1; i <= count; i++) {
		delete_data(i);
	}
}
node*& list::get_ptr(int pos) {
	if (pos == 0) return head;
	node * p = head;
	for (int i = 1; i < pos; i++)
		p = p->next;
	return p->next;
}
node * list::findk(node *head, int k) {
	node *p1 = head;
	node *p2 = NULL;
	for (int i = 0; i < k - 1; i++) {
		if (p1->next != NULL) p1 = p1->next;
		else return NULL;
	}
	p2 = head;
	while (p1->next != NULL) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2->next;
}

int main() {
	list l;
	l.create(10);
	node *t = l.findk(l.head, 3);
	cout << t->data;
	l.~list();
}