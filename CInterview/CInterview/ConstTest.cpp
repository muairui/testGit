#include "pch.h"
#include "ConstTest.h"


ConstTest::ConstTest():m_nA(10)
{
}
ConstTest::ConstTest(int x):m_nA(x)
{

}

ConstTest::~ConstTest()
{
}

int ConstTest::getValue()
{
	m_nB = 100;
	return m_nB;
}

int ConstTest::getValue() const
{
	return m_nB;
}

void ConstTest::function1(const int var)
{
	//var = 100;
	int test = var * 100;


	ConstTest b;                        // 普通对象，可以调用全部成员函数
	const ConstTest a;                  // 常对象，只能调用常成员函数、更新常成员变量
	const ConstTest *p = &a;            // 常指针
	const ConstTest &q = a;             // 常引用

	    // 指针
    char greeting[] = "Hello";
    char* p1 = greeting;                // 指针变量，指向字符数组变量
    const char* p2 = greeting;          // 指针变量，指向字符数组常量
    char* const p3 = greeting;          // 常指针，指向字符数组变量
    const char* const p4 = greeting;    // 常指针，指向字符数组常量
}
