#include<iostream>
using namespace std;

class MyClass
{
public:
	MyClass();
	~MyClass();

	void Test()
	{
	
	}
private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}


int main()
{
	MyClass c[100];

	for (int i = 0; i < 1000; ++i)
	{
		c[i].Test();
	}

	system("Pause");
	return 0;
}