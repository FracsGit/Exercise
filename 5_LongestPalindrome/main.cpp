#include<string>
#include<iostream>
using namespace std;

int LengthOfOddPalindrome(string& s, int size, int position)
{
	int length = 1;
	bool flag = true;

	for (int i = 1; position - i >= 0 && position + i < size && flag; ++i)
	{
		if (s[position - i] == s[position + i])
		{
			length += 2;
		}
		else
			flag = false;
	}

	return length;
}

int LengthOfEvenPalindrome(string& s, int size, int position)
{
	int length = 0;
	bool flag = true;

	for (int i = 0; position - i >= 0 && position + 1 + i < size && flag; ++i)
	{
		if (s[position - i] == s[position + 1 + i])
		{
			length += 2;
		}
		else
			flag = false;
	}

	return length;
}

string longestPalindrome(string s) 
{
	int size = s.size();
	
	if (size == 0)
		return s;
	if (size == 1)
		return s;

	int maxLength = 1;
	int position = 0;
	int palindromeType = 1;

	for (int i = 0; i < size; ++i)
	{
		int tempLength = 0;

		tempLength = LengthOfOddPalindrome(s, size, i);
		if (tempLength > maxLength)
		{
			maxLength = tempLength;
			position = i;
			palindromeType = 1;
		}

		tempLength = LengthOfEvenPalindrome(s, size, i);
		if (tempLength > maxLength)
		{
			maxLength = tempLength;
			position = i;
			palindromeType = 0;
		}
	}

	int tail;
	if(palindromeType == 1)
		tail = position - maxLength / 2;
	else
		tail = position - maxLength / 2 + 1;

	string result(s, tail, maxLength);

	return result;
}

int main()
{
	string s1 = "babad";
	string s2 = "cbbd";
	string s3 = "";
	string s4 = "a";
	string s5 = "bb";
	string s6 = "ab";
	string s7 = "aabba";
	string s8 = "aabbaad";

	cout << longestPalindrome(s1) << endl;
	cout << longestPalindrome(s2) << endl;
	cout << longestPalindrome(s3) << endl;
	cout << longestPalindrome(s4) << endl;
	cout << longestPalindrome(s5) << endl;
	cout << longestPalindrome(s6) << endl;
	cout << longestPalindrome(s7) << endl;
	cout << longestPalindrome(s8) << endl;

	system("Pause");
	return 0;
}
