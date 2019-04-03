#pragma once




class explictTestA
{
public :
	explictTestA(int) {}
	operator bool()const { return true; }
};
class explictTestB
{
public:
	explicit explictTestB(int) {}
	explicit operator bool()const { return true; }
};

class explictTest
{
public:
	void Test();
};
