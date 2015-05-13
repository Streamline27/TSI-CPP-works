#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void test1(){
	ifstream f("file.txt");
	if (f.is_open()){
		string a;
		getline(f, a);
		cout << a.c_str() << endl;
	}
	else cout << "Can't open file" << endl;

	f.close();
}

void test2(){
	ofstream f("file.txt", ios::in);
	f << "Privet" << endl;
	f << "Kak" << endl;
	f << "dela" << endl;
	f.seekp(0);
	f << "ZBS";
	f.close();
}

void test3(){

}


int main(){
	test2();

	system("PAUSE");
	return 0;
}