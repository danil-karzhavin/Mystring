#include<iostream>
#include<initializer_list>
#include"my_string.h"
using namespace std;

int main() {
	Mystring text({ 'h','e','l','l','o' });
	cout << text.get_str() << endl;
	cout << text.size() << endl;
	cout << text.capacity() << endl;
	
	return 0;
}