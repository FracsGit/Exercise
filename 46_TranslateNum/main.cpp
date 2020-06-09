#include<iostream>
#include<vector>
using namespace std;

int translateNum(int num) 
{
	int result = 1;
	int count = 0;
	int countN = 1;
	int countN_1 = 0;
	vector<int> bit;

	if (num == 0)
		return 1;

	while (num != 0)
	{
		bit.push_back(num % 10);
		num /= 10;
	}
	
	for (size_t i = 0; i < bit.size() - 1; ++i)
	{
		int temp = countN;
		countN += countN_1;
		countN_1 = temp;

		if (bit[i + 1] > 2 || bit[i + 1] == 0 || (bit[i + 1] == 2 && bit[i] > 5))
		{
			result *= countN;
			countN = 1;
			countN_1 = 0;
		}
	}

	countN += countN_1;
	result *= countN;

	return result;
}

int main()
{
	cout << translateNum(12258) << endl;
	cout << translateNum(0) << endl;
	cout << translateNum(3) << endl;
	cout << translateNum(9) << endl;
	cout << translateNum(11) << endl;
	cout << translateNum(31) << endl;
	cout << translateNum(17) << endl;
	cout << translateNum(25) << endl;
	cout << translateNum(26) << endl;
	cout << translateNum(999) << endl;
	cout << translateNum(4168410706) << endl;
	cout << 4168410706 << endl;
	cout << INT32_MAX << endl;

	system("Pause");
	return 0;
}