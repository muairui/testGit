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


	ConstTest b;                        // ��ͨ���󣬿��Ե���ȫ����Ա����
	const ConstTest a;                  // ������ֻ�ܵ��ó���Ա���������³���Ա����
	const ConstTest *p = &a;            // ��ָ��
	const ConstTest &q = a;             // ������

	    // ָ��
    char greeting[] = "Hello";
    char* p1 = greeting;                // ָ�������ָ���ַ��������
    const char* p2 = greeting;          // ָ�������ָ���ַ����鳣��
    char* const p3 = greeting;          // ��ָ�룬ָ���ַ��������
    const char* const p4 = greeting;    // ��ָ�룬ָ���ַ����鳣��
}
