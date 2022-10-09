#ifndef MY_STRING
#define MY_STRING
using namespace std;
class Mystring {
private:
	char* str = nullptr;
public:
	Mystring();
	Mystring(const char* str);
	Mystring(initializer_list<char> str);
	Mystring(string str);

	int size();
	int size(char*); // get a length of array

	int capacity();
	int capacity(char*);// get a length of array (+  "/0")

	char* mem_allocate(int);
	char* get_str();
};
#endif