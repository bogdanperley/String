#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"string.h"

int main()
{
	String str{ "Hello World" };
	String::iterator it{ str.begin() };
	++it;
	*it;
	std::cout << *it << std::endl;
	*it = 'F';
	str.print();
	int a{ 5 };
	a + 20;
	it + 10;
	str[5] = 'f';
	auto ch = str[5];
	it += 5;
	return 0;
}
