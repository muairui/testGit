#pragma once
#include<iostream>
using namespace std;
//������������Ϊ�˽�������ָ��ָ����������󣬲��û����ָ��ɾ�����������
class Shape
{
public :
	Shape()
	{
		printf("Shape gouzao\n");
	}
	virtual double calcArea() 
	{
		return 1 * 10;
	}
	virtual ~Shape() 
	{
		printf("Shape xigou\n");
	}

};
class Circle :public Shape
{
public:
	Circle()
	{
		printf("Circle gouzao\n");
	}
	virtual double calcArea() 
	{
		return 10 * 10;
	}
	virtual~Circle()
	{
		printf("Circle xigou\n");
	}

};
/*
˽���������������ã������ֻ���ڶ������ɣ�����new������
ԭ����C++��һ����̬�����ԣ��ڱ�������У����еķ��麯�����ö����������ɣ��麯��ҲҪ���ɷ����ԣ���
��ˣ�����ջ�����ɶ���ʱ��������Զ�����������������������Է��ʡ����ڶ������ɶ���ʱ�����������ɳ���Ա���ƣ���һ����Ҫ����������
ͬʱ�������ɶ�����ֱ��deleteɾ�����������̻���Ҫһ��ר�ŵĳ�Ա�����������е�destory()��������

������
��������һ���������ϣ��������֮ǰ������һЩ���飬������������˲���֪����
��ô��Ϳ�������дһ�������������Ҫ��������ȫ���������ٵ�������������
�����˼�ֻ�ܵ�������������������󣬴Ӷ���֤������ǰһ��������Ҫ��Ķ�����
*/
class Circle1
{
public:
	Circle1(){}

	void Destory()
	{
		delete this;
	}
private:
	~Circle1(){}
};

/*
ֻ����ջ��--->����ʹ��new����������
*/
class Circle2
{
public:
	Circle2() 
	{

	}
	int m_nB;
private:
	void *operator new (size_t size);
	void operator delete(void *p);

};
class ShapeTest
{
public:
	void Test()
	{
		Shape * shape1 = new Circle();
		shape1->calcArea();
		delete shape1;  // ��ΪShape������������������delete�ͷ��ڴ�ʱ���ȵ������������������ٵ��û���������������ֹ�ڴ�й©��
		shape1 = NULL;


		/*
		��C++�У���Ķ�������Ϊ���֣�һ���Ǿ�̬��������A a��
		��һ���Ƕ�̬��������A* ptr=new A�������ַ�ʽ���������
		*/
		Circle1 *p1 = new Circle1();
		cout << "new�����ַ " << p1 << endl;
		// delete p1; //�����������ֱ��delete
		p1->Destory();

		Circle2 b;
		cout << "�����ַ " << &b << endl;
		b.m_nB = 10;
		//Circle2 *p2 = new Circle2();// ���ɷ��� �������
	}
};