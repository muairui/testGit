#include "pch.h"
#include "StaticA.h"
#include<iostream>
char a = 'A'; // global variable
void msg()
{
	printf("Hello\n");

}
StaticA::StaticA()
{
	msg();
}


StaticA::~StaticA()
{
}

int StaticA::TestStatic()
{
	static int count = 10;//作用是保持变量内容的持久
	return count--;
}
