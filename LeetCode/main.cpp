#include "stdafx.h"

int main()
{
	int respace(vector<string>& dictionary, string sentence);

	vector<string> dictionary = { "looked", "just", "like", "her", "brother" };
	string sentence = "jesslookedjustliketimherbrother";
	
	cout << respace(dictionary, sentence) << endl;

	system("Pause");
	return 0;
}