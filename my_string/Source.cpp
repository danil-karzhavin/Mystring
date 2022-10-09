#include<iostream>
#include"my_string.h"
using namespace std;

int main() {
	Mystring Nina;
	//Mystring Nina("waste");
	cout << Nina.size() << endl;
	cout << Nina.capacity() << endl;
	return 0;
}