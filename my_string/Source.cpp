#include<iostream>
#include<initializer_list>
#include"my_string.h"
using namespace std;

int main() {
	MyString a1("hello hello "), a2("lo");
	a1 += a2;
	std::cout << a1.get_str() << " " << a2.get_str() << std::endl;

	return 0;
}