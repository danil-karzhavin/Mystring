#include<iostream>
#include<initializer_list>
#include"my_string.h"
using namespace std;

int main() {
	Mystring a5("hello", 4);
	cout << a5.get_str() << endl;
	cout << a5.size() << endl;
	cout << a5.capacity() << endl;
	return 0;
}