#include<string>
#include<iostream>
using namespace std;


bool validPalindrome(string s)
{
	int head = 0;
	int tail = s.size()-1;
	bool flag = true;
	int count = 0;

	do
	{
		if (s[head] != s[tail])
		{
			if (count > 0)
			{
				flag = false;
				break;
			}
			++count;
			
			for (int i = 1;count <= 1 && head +i< tail-i+1; ++i)
			{
				bool flagHead = true;
				bool flagTail = true;

				if (s[head + i] != s[tail - i +1])
					flagHead = false;
				if (s[head + i -1] != s[tail - i])
					flagTail = false;

				if (flagHead == false && flagTail == false)
				{
					++count;
					flag = false;
					break;
				}
				else if (flagHead == true && flagTail == false)
				{
					++head;
					break;
				}
				else if (flagHead == false && flagTail == true)
				{
					--tail;
					break;
				}				
			}
		}

		++head;
		--tail;
	} while (head < tail - 1 && flag == true);

	return flag;
}


int main()
{
	string s1("aba");
	string s2("abca");
	string s3("abc");
	string s4("aa");
	string s5("abcdef");
	string s6("a");
	string s7("abdbda");
	string s8("abddbda");
	string s9("abdbdbddbdbda");
	string s10("hbakab");

	cout << validPalindrome(s1) << endl;
	cout << validPalindrome(s2) << endl;
	cout << validPalindrome(s3) << endl;
	cout << validPalindrome(s4) << endl;
	cout << validPalindrome(s5) << endl;
	cout << validPalindrome(s6) << endl;
	cout << validPalindrome(s7) << endl;
	cout << validPalindrome(s8) << endl;
	cout << validPalindrome(s9) << endl;
	cout << validPalindrome(s10) << endl;

	system("Pause");
	return 0;
}