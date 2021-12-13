#include<iostream>
using namespace std;
class node {
public:
	int data;
	node*next;
};
class list {
public:
	void creattail();
	void creathead();
	void insert(int x);
	void dele(int x);
	void print();
private:
	node*head;
};
void list::creattail() {
	head = new node;
	head->next = NULL;
	node*tail;
	tail = head;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		node*s;
		s = new node;
		s->data = x;
		tail->next = s;
		tail = s;

	}
	tail->next = NULL;
}
void list::creathead() {
	head = new node;
	head->next = NULL;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		node*s;
		s = new node;
		s->data = x;
		s->next = head->next;
		head->next = s;
	}
}
void list::print() {
	node*p;
	p = head->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void list::insert(int x) {
	node*s, *p, *ppre;
	s = new node;
	s->data = x;
	p = head->next;
	ppre = head;
	while (p != NULL) {
		if (p->data > s->data)break;
		ppre = ppre->next;
		p = p->next;
	}
	s->next = p;
	ppre->next = s;
}
void list::dele(int x) {
	node*p, *ppre;
	p = head->next;
	ppre = head;
	while (p != NULL) {
		if (p->data == x)break;
		p = p->next;
		ppre = ppre->next;
	}
	ppre->next = p->next;
	delete p;
}
int main() {
	list l;
	cout << "请输入链表长度" << endl;
	int x;
	l.creattail();
	l.print();
	cout << "插入99,,101,102,103,104后" << endl;
	l.insert(99);
	l.insert(101);
	l.insert(102);
	l.insert(103);
	l.insert(104);
	l.print();
	cout << "输入删除的两个数字" << endl;
	cin >> x;
	l.dele(x);
	cin >> x;
	l.dele(x);
	l.print();
	cout << "插入999" << endl;
	l.insert(999);
	l.print();
	/*int x;
	cin>>x;
	l.dele(x);
	l.print();
	cin>>x;
	l.insert(x);
	l.print();*/
	return 0;
}