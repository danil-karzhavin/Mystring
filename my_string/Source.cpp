#include<iostream>
#include<initializer_list>
#include"my_string.h"
using namespace std;

int main() {
	Mystring a7("helhiigugihlo");
	std::cout << a7.get_str() << " " << a7.size() << " " << a7.capacity() << std::endl;
	Mystring a8(a7);
	std::cout << a8.get_str() << " " << a8.size() << " " << a8.capacity() << std::endl;

	return 0;
}