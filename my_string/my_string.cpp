#include<iostream>
#include<initializer_list>
#include"my_string.h"
#include"func.h"
using namespace std;

Mystring::Mystring() {
}
//when the string is completely written in the parameter
Mystring::Mystring(const char* str) {
	char* tmp = (char*)str;// ������� ��� ��������� ��� �������� ����� ������, � ����� ����������� ����������� � ����� ������.
	int len = capacity(tmp); // �������� ����� ������
	this->str = mem_allocate(len);// �������� ��� ����� ������ ������
	copy_str(len, this->str, tmp); // �������� ���������� ����� ������ � ���������� ������
}
Mystring::Mystring(initializer_list<char> str) {
	char* end = (char*)str.end();
	*end = NULL; // add a \0 symbol
	char* str_buffer = (char*)str.begin();// ������������� �������� ������ � ���������� char
	this->str = mem_allocate(capacity(str_buffer));// allocate a new memore for this->str;
	copy_str(capacity(str_buffer), this->str, str_buffer);
}
Mystring::Mystring(string str) {
	char* tmp = &str[0];
	int len = 0;
	while (str[len] != NULL) 
		len++;
	len++;
	this->str = mem_allocate(len);
	copy_str(len, this->str, tmp);
}
Mystring::Mystring(const char* str, int len) {
	char* tmp = (char*)str;
	this->str = mem_allocate(len + 1);
	copy_str(len, this->str, tmp);
	*(this->str + len) = 0;
}


// � ���� ������ �������� ����� ������
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
	return count; // ������� ����� ������� char
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
	return (size(str) + 1); // ������� ����� ������� char
}


// allocate memory
char* Mystring::mem_allocate(int len) {
	this->str = new char[len];
	return this->str;
}
