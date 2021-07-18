//计科2班 2018211958 孙淼
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    ofstream file("test1.txt",ios::app);
    file<<"已成功添加字符！";
    file.close();
    char ch;
    ifstream file1("test1.txt");
    while(file1.get(ch))
    cout<<ch;
    file1.close();
}

已成功写入文件！已成功添加字符！ 
--------------------------------
Process exited after 0.2275 seconds with return value 0
请按任意键继续. . .
