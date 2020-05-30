#include<list>
#include<iostream>
using namespace std;

int main()
{
	list<int> testList;
	for (auto ite = testList.begin(); ite != testList.end(); ++ite)
	{
		cout << *ite << endl;
	}

	testList.insert(testList.begin(), 3);
	testList.insert(testList.begin(), 2);
	testList.insert(testList.begin(), 1);
	testList.insert(testList.begin(), 0);
	int i = 0;
	for (auto ite = testList.begin(); ite != testList.end(); ++ite)
	{
		cout << *ite << endl;
		if (i < 10)
		{
			testList.insert(ite, i+10);
			++i;
		}
	}
	for (auto ite = testList.begin(); ite != testList.end(); ++ite)
	{
		cout << *ite << endl;
	}

	system("Pause");
	return 0;
}