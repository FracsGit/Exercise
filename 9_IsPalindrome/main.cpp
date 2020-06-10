#include<iostream>
using namespace std;

bool isPalindrome(int x) 
{
	if (x < 0)
		return false;

	long long temp = x;
	long long palindrome = 0;
	while (temp != 0)
	{
		palindrome *= 10;
		palindrome += temp % 10;
		temp /= 10;
	}

	if (x != palindrome)
		return false;

	return true;
}

int main()
{
	cout << isPalindrome(121) << endl;
	cout << isPalindrome(-121) << endl;
	cout << isPalindrome(10) << endl;
	cout << isPalindrome(INT32_MAX) << endl;
	cout << isPalindrome(INT32_MIN) << endl;
	cout << isPalindrome(1234554321) << endl;
	cout << isPalindrome(123454321) << endl;
	cout << isPalindrome(0) << endl;


	system("Pause");
	return 0;
}