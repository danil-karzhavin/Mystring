#include<iostream>
#include"func.h"
using namespace std;
void copy_str(int len, char* arr1, char* arr2) { // copy from arr2 to arr1
	for (int i = 0; i < len; i++) {
		*(arr1 + i) = *(arr2 + i);
	}
}
void merge_str(char* str, char* s1, char* s2) {
	int count = 0;
	while (*s1 != NULL) {
		*(str + count) = *s1;
		s1++;
		count++;
	}
	while (*s2 != NULL) {
		*(str + count) = *s2;
		count++;
		s2++;
	}
	*(str + count) = NULL;
}
