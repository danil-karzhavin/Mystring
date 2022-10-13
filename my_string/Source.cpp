#include<iostream>
#include<initializer_list>
#include"my_string.h"
using namespace std;

int main() {
	MyString a1("abc"), a2("abc  ");
	cout << (a2 != a1) << endl;

	return 0;
}