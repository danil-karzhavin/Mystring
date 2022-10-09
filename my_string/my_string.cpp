#include<iostream>
#include<initializer_list>
#include"my_string.h"
#include"func.h"
using namespace std;

Mystring::Mystring() {
}
//when the string is completely written in the parameter
Mystring::Mystring(const char* str) {
	char* tmp = (char*)str;// создали доп указатель для подсчета длины строки, а также копирования содержимого в новую строку.
	int len = capacity(tmp); // получили длину строки
	this->str = mem_allocate(len);// выделили под новую строку память
	copy_str(len, this->str, tmp); // копируем содержимое конст строки в выделенную память
}
Mystring::Mystring(initializer_list<char> str) {
	//const char* begin = str.begin();
	char* end = (char*)str.end();
	*end = NULL; // add a \0 symbol
	char* str_buffer = (char*)str.begin();// преобразовали вводимую строку в нормальный char
	this->str = mem_allocate(capacity(str_buffer));// allocate a new memore for this->str;
	copy_str(capacity(str_buffer), this->str, str_buffer);
}


// в этом методе получаем длину строки
int Mystring::size() {
	if (this->str == nullptr)
		return 0;
	return size(this->str);
}
// get a lenght of string
int Mystring::size(char* str) {
	int count = 0;
	while (*str != NULL) {
		count++;
		str++;
	}
	return count; // вернули длину массива char
}
char* Mystring::get_str() {
	return this->str;
}


// get a length of string (+  "/0")
int Mystring::capacity() {
	if (this->str == nullptr)
		return 0;
	return size(this->str) + 1;
}
// get a length of string (+  "/0")
int Mystring::capacity(char* str) {
	return (size(str) + 1); // вернули длину массива char
}


// allocate memory
char* Mystring::mem_allocate(int len) {
	this->str = new char[len];
	return this->str;
}
