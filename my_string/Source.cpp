#include<iostream>
#include<initializer_list>
#include"my_string.h"
using namespace std;

int main() {
	string s = "hello hello hello hello";
	Mystring str(s);
	cout << str.get_str() << " " << str.size() << " " << str.capacity() << endl;
	
	return 0;
}