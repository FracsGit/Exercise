#include<iostream>
#include<string>
using namespace std;

string decodeString(string &s, int size, int &i)
{
	int repeat = 0;
	string result = "";
	string temp = "";

	for (; i < size; ++i)
	{
		if (isdigit(s[i]))
		{
			repeat *= 10;
			repeat += (s[i] - '0');
		}
		else if (s[i] == '[')
		{
			temp = decodeString(s, size, ++i);

			while (repeat > 0)
			{
				result += temp;
				--repeat;
			}
			temp = "";
		}
		else if (isalpha(s[i]))
		{
			result += s[i];
		}
		else if (s[i] == ']')
		{
			return result;
		}
	}

	return result;
}

string decodeString(string s) 
{
	string result = "";
	int size = s.size();
	int i = 0;
	if (size > 0)
	{
		result = decodeString(s, size, i);
	}

	return result;
}

int main()
{
	string s1 = "3[a]2[bc]";
	string s2 = "3[a2[c]]";
	string s3 = "2[abc]3[cd]ef";
	string s4 = "";

	cout << decodeString(s1) << endl;
	cout << decodeString(s2) << endl;
	cout << decodeString(s3) << endl;
	cout << decodeString(s4) << endl;


	system("Pause");
	return 0;
}