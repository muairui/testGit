#pragma once
class ConstTest
{
public:
	ConstTest();
	ConstTest(int x);
	~ConstTest();
	int getValue();
	int getValue() const;
	void function1(const int var);


private:
	const int m_nA;
	int m_nB;

};

