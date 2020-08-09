#include "stdafx.h"

int main()
{
	vector<string> restoreIpAddresses(string s);
	
	vector<string> result = restoreIpAddresses("25525511135");

	for (string s : result)
		cout << s << endl;

	system("Pause");
	return 0;
}