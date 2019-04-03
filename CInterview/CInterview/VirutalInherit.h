#pragma once

#include<iostream>
using  namespace std;
//虚继承 解决 钻石 问题

/*
虚继承用于解决多继承条件下的菱形继承问题（浪费存储空间、存在二义性）。

底层实现原理与编译器相关，一般通过虚基类指针和虚基类表实现，
每个虚继承的子类都有一个虚基类指针（占用一个指针的存储空间，4字节）和虚基类表（不占用类对象的存储空间）
（需要强调的是，虚基类依旧会在子类里面存在拷贝，只是仅仅最多存在一份而已，并不是不在子类里面了）；
当虚继承的子类被当做父类继承时，虚基类指针也会被继承。

实际上，vbptr 指的是虚基类表指针（virtual base table pointer），
该指针指向了一个虚基类表（virtual table），虚表中记录了虚基类与本类的偏移地址；通过偏移地址，
这样就找到了虚基类成员，而虚继承也不用像普通多继承那样维持着公共基类（虚基类）的两份同样的拷贝，节省了存储空间。
*/
class GrandFather
{
public:
	GrandFather() = default;
	GrandFather(int v) :value(v)
	{
		cout << "调用了GrandFather类的构造函数" << endl;
	}
	int value;
};
class Father1 : public GrandFather
{
public:
	Father1() = default;
	Father1(int v) :GrandFather(v)
	{
		cout << "调用Father1类的构造函数" << endl;
	}
	void set_value(int value)
	{
		this->value = value;
	}
};

class Father2 : public GrandFather
{
	//第二层基类Father2
public:
	Father2() = default;
	Father2(int v) :GrandFather(v)
	{
		cout << "调用Father2类的构造函数" << endl;
	}
	int get_value()
	{ //获取value的值
		return this->value;
	}
};
class Son :public Father1, public Father2
{
	//第三次层类Son
public:
	Son() = default;
	Son(int v) :Father1(v), Father2(v)
	{
		cout << "调用Son类的构造函数" << endl;
	}
};

class VirutalInheritTest
{
public:
	void Test()
	{
		Son s(10);
		s.set_value(20);
		printf("%d", s.get_value());
		cout << "Father1类创建的子对象的value值：" << s.Father1::value << endl;
		cout << "Father2类创建的子对象的value值：" << s.Father2::value << endl;
	}
};