#include "Person.h"
#include <iostream>
int main()
{
	string name = "ZhangSan", address = "ShangHai";
	Person someone(name, address);

	cout << someone.GetName() << ": " << someone.GetAddress() << endl;
	system("Pause");
}