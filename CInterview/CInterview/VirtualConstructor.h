#pragma once
#include<iostream>
using namespace std;
//虚析构函数是为了解决基类的指针指向派生类对象，并用基类的指针删除派生类对象。
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
私有析构函数的作用：令对象只能在堆上生成，即用new方法。
原理是C++是一个静态绑定语言，在编译过程中，所有的非虚函数调用都必须分析完成（虚函数也要检查可访问性）。
因此，当在栈上生成对象时，对象会自动析构，即析构函数必须可以访问。而在堆上生成对象时，析构步骤由程序员控制，不一定需要析构函数。
同时，此生成对象不能直接delete删除，析构过程还需要一个专门的成员函数（代码中的destory()函数）。

举例：
比如这样一种情况，你希望在析构之前必须做一些事情，但是用你类的人并不知道，
那么你就可以重新写一个函数，里面把要做的事情全部做完了再调用析构函数。
这样人家只能调用你这个函数析构对象，从而保证了析构前一定会做你要求的动作。
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
只能在栈上--->不能使用new来创建对象
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
		delete shape1;  // 因为Shape有虚析构函数，所以delete释放内存时，先调用子类析构函数，再调用基类析构函数，防止内存泄漏。
		shape1 = NULL;


		/*
		在C++中，类的对象建立分为两种，一种是静态建立，如A a；
		另一种是动态建立，如A* ptr=new A；这两种方式是有区别的
		*/
		Circle1 *p1 = new Circle1();
		cout << "new分配地址 " << p1 << endl;
		// delete p1; //编译出错，不能直接delete
		p1->Destory();

		Circle2 b;
		cout << "分配地址 " << &b << endl;
		b.m_nB = 10;
		//Circle2 *p2 = new Circle2();// 不可访问 编译出错
	}
};