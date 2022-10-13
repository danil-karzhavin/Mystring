#ifndef MY_STRING
#define MY_STRING
using namespace std;
class MyString {
private:
	char* str = nullptr;
public:
	MyString();
	MyString(const char* str);
	MyString(initializer_list<char> str);
	MyString(string str);
	MyString(const char*, int);
	MyString(int, char);
	MyString(MyString&);
	MyString(char*);
	~MyString();

	int size();
	int size(char*); // get a length of array

	int capacity();
	int capacity(char*);// get a length of array (+  "/0")

	char* mem_allocate(int);
	char* mem_reallocate(int, char*); // перевыдел€ем пам€ть под сущ. строку на другой размер
	char* get_str();

	MyString operator + (MyString&);
	void operator = (MyString&);
	void operator = (const char*);
	void operator = (string);
	void operator = (char);
	void operator += (MyString&);
	void operator += (string&);
	char operator [] (int);
	bool operator > (MyString&);
	bool operator < (MyString&);
	bool operator >= (MyString&);
	bool operator <= (MyString&);
	bool operator == (MyString&);
	bool operator != (MyString&);
};
#endif