#include "stdafx.h"

int main()
{
	bool isMatch(string s, string p);

	string s = "aaab";
	string p = "b**";

	cout << isMatch(s, p) << endl;

	system("Pause");
	return 0;
}