#include<iostream>
using namespace std;
class list {
public:
	list();                                       //初始化对应的构造函数
	int length()const;                            //求长度
	void create(int i);                           //创建顺序表
	int get_element(const int i, int &x)const;    //按序号取元素(序号从1而非从0开始）
	int locate(const int x)const;                 //搜索元素
	int insert(const int i, const int x);         //插入元素
	int delete_element(const int i);              //删除元素
	~list();
private:
	int data[100];
	int count;
};
list::list() { count = 0; }
int list::length()const 
{
	return count;
    cout << count;
}
void list::create(int i)
{ 
	int x, int y = 1;
	cin >> x;
	while (y != n) {
		count++;
		cin >> x;
		Z
		y++;
	}
}
int list::get_element(const int i, int &x)const     //用变量x返回所求出的元素
{
	if (i <= 0 || i > count)
		return -1;
	x = data[i - 1];
	return 1;
}
int list::locate(const int x)const
{
	for (int i = 0; i < length(); i++)                  //应当熟练掌握for语句
		if (data[i] == x)return (i + 1);            //数组元素的下标比序号少1
	return -1;                                      //执行到此语句，表明前面没有找到
}
int list::insert(const int i, const int x)
{
	if (count = 100)                             //表长有最大值，超过则溢出
		return -1;
	if (i<1 || i>length() + 1)
		return -1;                         //插入位置要合法
	for (int j = count - 1; j >= i - 1; j--)
		data[j + 1] = data[j];                      //往后移动元素
	data[i - 1] = x;                            //填入插入元素
	count++;                                        //修改表长
	return 0;
}
int list::delete_element(const int i)
{
	if (length() == 0)
		return -1;                           //空表不能删除元素
	if (i<1 || i>length())
		return -1;                         //删除元素不存在
	for (int j = i + 1; j <= length(); j++)
		data[j - 2] = data[j - 1];                  //向前批量移动元素
	count--;                                        //表长度减1
	return 0;
}
list::~list() 
{
	for (int i = 1; i <= count; i++)
		delete_element(i);
}
int main()
{
	list l;
	//list();此处理是否多余？百度说构造函数不能被直接调用，必须通过new运算符在创建对象时才会自动调用；而一般的方法是在程序执行到它的时候被调用的；
	l.create(3);
	l.length();
	//l.get_element(10);//???
	l.locate(1);
	l.insert(1, 37);
	l.delete_element(2);
	l.~list();
	cin.get();
	cin.get();

}