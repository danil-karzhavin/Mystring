#include<iostream>
#include<initializer_list>
#include"my_string.h"
using namespace std;

int main() {
	MyString a3;
	a3 = '!';
	std::cout << a3.get_str() << std::endl;
	std::cout << a3.size() << std::endl;
	std::cout << a3.capacity() << std::endl;

	return 0;
}