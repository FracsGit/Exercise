#include<string>
#include<iostream>
using namespace std;


int lengthOfLastWord(string s) 
{
	int length = 0;
	int tempLength = 0;

	for (auto c: s)
	{
		if (isspace(c))
		{
			if (tempLength != 0)
				length = tempLength;
			tempLength = 0;
		}
		if(isalpha(c))
			++tempLength;
	}
	if(tempLength!=0)
		length = tempLength;


	return length;
}


int main()
{
	string s1("Hello World");
	string s2("b a  ");
	string s3("a");
	string s4("Hello World asefasefs ");
	string s5(" Hello World asefsefasfese ");
	cout << lengthOfLastWord(s1) << endl;
	cout << lengthOfLastWord(s2) << endl;
	cout << lengthOfLastWord(s3) << endl;
	cout << lengthOfLastWord(s4) << endl;
	cout << lengthOfLastWord(s5) << endl;
	string s6;
	cout << lengthOfLastWord(s6) << endl;

	system("Pause");
	return 0;
}