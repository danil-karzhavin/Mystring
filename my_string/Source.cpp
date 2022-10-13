#include<iostream>
#include<initializer_list>
#include"my_string.h"
using namespace std;

int main() {
	MyString a1("Hello world!");
	std::string s1;
	s1 = a1.data();
	std::cout << s1 << std::endl;

	return 0;
}