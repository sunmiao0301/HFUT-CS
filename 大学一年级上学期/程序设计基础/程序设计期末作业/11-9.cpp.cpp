//计科2班 2018211958 孙淼
#include<iostream>
#include<fstream>
using namespace std;

int main() {
	ofstream file;
	file.open("input.txt");
	file<<"aaaaaaaa\nbbbbbbbb\ncccccccc";
	file.close();

	ifstream filei("input.txt");
	ofstream fileo;
	fileo.open("output.txt");

	char c;
	filei>>noskipws;
	int i=1;
	fileo<<i<<".";
	cout<<i<<".";
	while(filei>>c) {
		if(c=='\n') {
			i++;
			fileo<<"\n";
			cout<<"\n";
			fileo<<i<<".";
			cout<<i<<".";
		} else {
			fileo<<c;
			cout<<c;
		}
	}
	filei.close();
	fileo.close();
}

1.aaaaaaaa
2.bbbbbbbb
3.cccccccc
--------------------------------
Process exited after 0.1828 seconds with return value 0
请按任意键继续. . .
