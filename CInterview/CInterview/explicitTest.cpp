#include "pch.h"
#include "explicitTest.h"
void doA(explictTestA a) 
{

}

void doB(explictTestB b) 
{

}
/*

	explicit ���ι��캯��ʱ�����Է�ֹ��ʽת���͸��Ƴ�ʼ��
	explicit ����ת������ʱ�����Է�ֹ��ʽת������ ���ﾳת�� ����

*/
void explictTest::Test()
{
	explictTestA a1(1);		// OK��ֱ�ӳ�ʼ��
	explictTestA a2 = 1;		// OK�����Ƴ�ʼ��
	explictTestA a3{ 1 };		// OK��ֱ���б��ʼ��
	explictTestA a4 = { 1 };		// OK�������б��ʼ��
	explictTestA a5 = (explictTestA)1;		// OK������ static_cast ����ʽת�� 
	doA(1);			// OK������� int �� A ����ʽת��
	if (a1);		// OK��ʹ��ת������ A::operator bool() �Ĵ� A �� bool ����ʽת��
	bool a6��a1��;		// OK��ʹ��ת������ A::operator bool() �Ĵ� A �� bool ����ʽת��
	bool a7 = a1;		// OK��ʹ��ת������ A::operator bool() �Ĵ� A �� bool ����ʽת��
	bool a8 = static_cast<bool>(a1);  // OK ��static_cast ����ֱ�ӳ�ʼ��



	explictTestB b1(1);		// OK��ֱ�ӳ�ʼ��
	//explictTestB b2 = 1;		// ���󣺱� explicit ���ι��캯���Ķ��󲻿��Ը��Ƴ�ʼ��
	explictTestB b3{ 1 };		// OK��ֱ���б��ʼ��
	//explictTestB b4 = { 1 };		// ���󣺱� explicit ���ι��캯���Ķ��󲻿��Ը����б��ʼ��
	explictTestB b5 = (explictTestB)1;		// OK������ static_cast ����ʽת��
	//doB(1);			// ���󣺱� explicit ���ι��캯���Ķ��󲻿��Դ� int �� B ����ʽת��
	if (b1);		// OK���� explicit ����ת������ B::operator bool() �Ķ�����Դ� B �� bool �İ��ﾳת��
	bool b6(b1);		// OK���� explicit ����ת������ B::operator bool() �Ķ�����Դ� B �� bool �İ��ﾳת��
	//bool b7 = b1;		// ���󣺱� explicit ����ת������ B::operator bool() �Ķ��󲻿�����ʽת��
	bool b8 = static_cast<bool>(b1);  // OK��static_cast ����ֱ�ӳ�ʼ��
}
