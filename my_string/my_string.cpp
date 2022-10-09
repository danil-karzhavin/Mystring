#include<iostream>
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
