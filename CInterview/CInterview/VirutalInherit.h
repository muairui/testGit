#pragma once

#include<iostream>
using  namespace std;
//��̳� ��� ��ʯ ����

/*
��̳����ڽ����̳������µ����μ̳����⣨�˷Ѵ洢�ռ䡢���ڶ����ԣ���

�ײ�ʵ��ԭ�����������أ�һ��ͨ�������ָ���������ʵ�֣�
ÿ����̳е����඼��һ�������ָ�루ռ��һ��ָ��Ĵ洢�ռ䣬4�ֽڣ�����������ռ�������Ĵ洢�ռ䣩
����Ҫǿ�����ǣ���������ɻ�������������ڿ�����ֻ�ǽ���������һ�ݶ��ѣ������ǲ������������ˣ���
����̳е����౻��������̳�ʱ�������ָ��Ҳ�ᱻ�̳С�

ʵ���ϣ�vbptr ָ����������ָ�루virtual base table pointer����
��ָ��ָ����һ��������virtual table��������м�¼��������뱾���ƫ�Ƶ�ַ��ͨ��ƫ�Ƶ�ַ��
�������ҵ���������Ա������̳�Ҳ��������ͨ��̳�����ά���Ź������ࣨ����ࣩ������ͬ���Ŀ�������ʡ�˴洢�ռ䡣
*/
class GrandFather
{
public:
	GrandFather() = default;
	GrandFather(int v) :value(v)
	{
		cout << "������GrandFather��Ĺ��캯��" << endl;
	}
	int value;
};
class Father1 : public GrandFather
{
public:
	Father1() = default;
	Father1(int v) :GrandFather(v)
	{
		cout << "����Father1��Ĺ��캯��" << endl;
	}
	void set_value(int value)
	{
		this->value = value;
	}
};

class Father2 : public GrandFather
{
	//�ڶ������Father2
public:
	Father2() = default;
	Father2(int v) :GrandFather(v)
	{
		cout << "����Father2��Ĺ��캯��" << endl;
	}
	int get_value()
	{ //��ȡvalue��ֵ
		return this->value;
	}
};
class Son :public Father1, public Father2
{
	//�����β���Son
public:
	Son() = default;
	Son(int v) :Father1(v), Father2(v)
	{
		cout << "����Son��Ĺ��캯��" << endl;
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
		cout << "Father1�ഴ�����Ӷ����valueֵ��" << s.Father1::value << endl;
		cout << "Father2�ഴ�����Ӷ����valueֵ��" << s.Father2::value << endl;
	}
};