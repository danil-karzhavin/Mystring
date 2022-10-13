#include<iostream>
#include<initializer_list>
#include"my_string.h"
using namespace std;

int main() {
	MyString a3("I like ");
	std::string s1 = "Test 3";
	a3 += s1;
	std::cout << a3.get_str() << std::endl;
	cout << s1 << endl;

	return 0;
}