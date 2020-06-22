#include<string>
#include<iostream>
using namespace std;

bool Check(const string &value, int n)
{
	if (value.size() % n != 0)
		return false;
	int size = value.size();
	int length = size / n;
	string s(value, 0, length);
	for (int p = length; p < size; p += length)
	{
		if (value.compare(p, length, s) != 0)
			return false;
	}
	return true;
}

bool Check(const string &pattern, const string &value, int lengthA, int lengthB)
{
	string sa(value, pattern.find('a') * lengthB, lengthA);
	string sb(value, pattern.find('b') * lengthA, lengthB);
	if (sa == sb)
		return false;

	for (size_t l = 0, r = 0; l < pattern.size(); ++l)
	{
		if (pattern[l] == 'a')
		{
			if (value.compare(r, lengthA, sa) != 0)
				return false;
			r += lengthA;
		}
		else
		{
			if (value.compare(r, lengthB, sb) != 0)
				return false;
			r += lengthB;
		}
	}
	return true;
}

bool patternMatching(string pattern, string value) 
{
	int a = 0, b = 0;
	for (char c : pattern)
	{
		if (c == 'a')
			++a;
		else
			++b;
	}

	//边界条件判断
	int sizePattern = pattern.size();
	int sizeValue = value.size();
	if ((sizePattern == 0 && sizeValue == 0)|| sizePattern == 1)
		return true;
	if (sizePattern == 0 && sizeValue != 0)
		return false;
	if (a == 0)
		return Check(value, b);
	if (b == 0)
		return Check(value, a);

	//可能的ab取值
	for (int lengthA = sizeValue / a; lengthA >= 0; --lengthA)
	{
		int lengthB = sizeValue - lengthA * a;
		if (lengthB % b == 0)
		{
			lengthB /= b;
			if (Check(pattern, value, lengthA, lengthB))
				return true;
		}
	}
	return false;
}

int main()
{
	string sp, sv;
	sp = "abba";
	sv = "dogcatcatdog";
	cout << patternMatching(sp, sv) << endl;

	sp = "abba";
	sv = "dogcatcatfish";
	cout << patternMatching(sp, sv) << endl;

	sp = "aaaa";
	sv = "dogcatcatdog";
	cout << patternMatching(sp, sv) << endl;

	sp = "abba";
	sv = "dogdogdogdog";
	cout << patternMatching(sp, sv) << endl;

	system("Pause");
	return 0;
}