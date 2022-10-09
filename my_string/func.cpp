#include<iostream>
#include"func.h"
using namespace std;
void copy_str(int len, char* arr1, char* arr2) { // copy from arr2 to arr1
	for (int i = 0; i < len; i++) {
		*(arr1 + i) = *(arr2 + i);
	}
}
