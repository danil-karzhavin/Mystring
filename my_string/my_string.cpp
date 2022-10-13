#include<iostream>
#include<initializer_list>
#include"my_string.h"
#include"func.h"
using namespace std;

MyString::MyString() {
}
//when the string is completely written in the parameter
MyString::MyString(const char* str) {
	char* tmp = (char*)str;// создали доп указатель для подсчета длины строки, а также копирования содержимого в новую строку.
	int len = capacity(tmp); // получили длину строки
	this->str = mem_allocate(len);// выделили под новую строку память
	copy_str(len, this->str, tmp); // копируем содержимое конст строки в выделенную память
}
MyString::MyString(initializer_list<char> str) {
	char* end = (char*)str.end();
	*end = NULL; // add a \0 symbol
	char* str_buffer = (char*)str.begin();// преобразовали вводимую строку в нормальный char
	this->str = mem_allocate(capacity(str_buffer));// allocate a new memore for this->str;
	copy_str(capacity(str_buffer), this->str, str_buffer);
}
MyString::MyString(string str) {
	char* tmp = &str[0];
	int len = 0;
	while (str[len] != NULL) 
		len++;
	len++;
	this->str = mem_allocate(len);
	copy_str(len, this->str, tmp);
}
MyString::MyString(const char* str, int len) {
	char* tmp = (char*)str;
	this->str = mem_allocate(len + 1);
	copy_str(len, this->str, tmp);
	*(this->str + len) = 0;
}
MyString::MyString(int len, char s) {//Mystring a5(5, '!');
	this->str = mem_allocate(len + 1);
	for (int i = 0; i < len; i++)
		*(this->str + i) = s;
	*(this->str + len) = 0;
}
MyString::MyString(MyString& s) {
	char* tmp = s.get_str(); // получаю указаетель на строку из другого объекта
	int len = s.capacity();
	this->str = mem_allocate(len);
	copy_str(len, this->str, tmp);
}
MyString::MyString(char* str) {
	int len = capacity(str);
	this->str = mem_allocate(len);
	copy_str(len, this->str, str);
}
MyString::~MyString() {
	delete[] this->str;
	this->str = nullptr;
}


// в этом методе получаем длину строки
int MyString::size() {
	if (this->str == nullptr)
		return 0;
	return size(this->str);
}
// get a lenght of string
int MyString::size(char* str) {
	int count = 0;
	while (*str != NULL) {
		count++;
		str++;
	}
	return count; // вернули длину массива char
}
char* MyString::get_str() {
	return this->str;
}


// get a length of string (+  "/0")
int MyString::capacity() {
	if (this->str == nullptr)
		return 0;
	return size(this->str) + 1;
}
// get a length of string (+  "/0")
int MyString::capacity(char* str) {
	return (size(str) + 1); // вернули длину массива char
}


// allocate memory
char* MyString::mem_allocate(int len) {
	this->str = new char[len];
	return this->str;
}
// первыделяет память нового размера и возвращает указатель на нее, копируя в новую память содержимое старой строки, старую строку потом удаляем
char* MyString::mem_reallocate(int new_len, char* str) {
	char* tmp = new char[new_len];
	int old_len = capacity(str);
	int res_len = (new_len >= old_len) ? old_len : new_len;
	for (int i = 0; i < res_len - 1; i++) {
		*(tmp + i) = *(str + i);
	}
	delete[] str;
	return tmp;
}

MyString MyString::operator + (MyString& s2) {
	int len1 = size();
	int len2 = s2.size();
	MyString obj;
	obj.str = new char[len1 + len2 + 1];
	merge_str(obj.str, this->str, s2.get_str());
	return obj;
}
void MyString::operator=(MyString& s2)
{
	if (this->str != nullptr) {
		delete[] str;
	}
	int size_2 = s2.capacity();
	this->str = mem_allocate(size_2);
	copy_str(size_2, this->str, s2.get_str());
}
void MyString::operator = (const char* str) {
	MyString s2(str);
	int size_2 = s2.capacity();
	this->str = mem_allocate(size_2);
	copy_str(size_2, this->str, s2.get_str());
}
void MyString::operator = (string str) {
	MyString s2(str);
	int size_2 = s2.capacity();
	this->str = mem_allocate(size_2);
	copy_str(size_2, this->str, s2.get_str());
}
void MyString::operator= (char s) {
	MyString s2(1, s);
	int size_2 = s2.capacity();
	this->str = mem_allocate(size_2);
	copy_str(size_2, this->str, s2.get_str());
}
void MyString::operator +=(MyString& s2) {
	int len1 = this->size(); // старая длина строки
	int new_len = this->size() + s2.size() + 1;
	this->str = mem_reallocate(new_len, this->str);// перевыделили память на длину new_len, скопировали туда содержимое this->str, затем очистили this->str.
	for (int i = len1, j = 0; i < this->size(); i++, j++) {
		*(this->str + i) = *(s2.get_str() + j);
	}
}
void MyString::operator +=(string& str2) {
	MyString s2(str2);
	int len1 = this->size(); // старая длина строки
	int new_len = this->size() + s2.size() + 1;
	this->str = mem_reallocate(new_len, this->str);// перевыделили память на длину new_len, скопировали туда содержимое this->str, затем очистили this->str.
	for (int i = len1, j = 0; i < this->size(); i++, j++) {
		*(this->str + i) = *(s2.get_str() + j);
	}
}
char MyString::operator[] (int i) {
	return this->str[i];
}
bool MyString::operator> (MyString& str2) {
	int len1 = this->size();
	int len2 = str2.size();
	bool tmp;
	int len = (len1 >= len2) ? len2 : len1;
	for (int i = 0; i < len; i++) {
		tmp = (this->str[i] > str2.get_str()[i]) ? true : false;
		break;
	}
	return tmp;
}
bool MyString::operator>= (MyString& str2) {
	int len1 = this->size();
	int len2 = str2.size();
	bool tmp;
	int len = (len1 >= len2) ? len2 : len1;
	for (int i = 0; i < len; i++) {
		if (this->str[i] != str2.get_str()[i]) {
			tmp = (this->str[i] >= str2.get_str()[i]) ? true : false;
			break;
		}
	}
	return tmp;
}
bool MyString::operator< (MyString& str2) {
	int len1 = this->size();
	int len2 = str2.size();
	bool tmp;
	int len = (len1 >= len2) ? len2 : len1;
	for (int i = 0; i < len; i++) {
		tmp = (this->str[i] < str2.get_str()[i]) ? true : false;
		break;
	}
	return tmp;
}
bool MyString::operator<= (MyString& str2) {
	int len1 = this->size();
	int len2 = str2.size();
	bool tmp;
	int len = (len1 >= len2) ? len2 : len1;
	for (int i = 0; i < len; i++) {
		if (this->str[i] != str2.get_str()[i]) {
			tmp = (this->str[i] <= str2.get_str()[i]) ? true : false;
			break;
		}
	}
	return tmp;
}
bool MyString::operator == (MyString& str2) {
	int len1 = this->size();
	int len2 = str2.size();
	bool tmp;
	int len = (len1 >= len2) ? len2 : len1;
	for (int i = 0; i < len; i++) {
		if (this->str[i] != str2.get_str()[i]) {
			return false;
		}
	}
	if (len1 == len2)
		return true;
	else return false;
}
bool MyString::operator != (MyString& str2) {
	int len1 = this->size();
	int len2 = str2.size();
	bool tmp;
	int len = (len1 >= len2) ? len2 : len1;
	for (int i = 0; i < len; i++) {
		if (this->str[i] != str2.get_str()[i]) {
			return true;
		}
	}
	if (len1 != len2)
		return true;
	else return false;
}
char* MyString::c_str() {
	return this->str;
}
string MyString::data() {
	string tmp = (string)this->str;
	return tmp;
}
