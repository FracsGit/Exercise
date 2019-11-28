#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	//ex2_7
	string line;
	vector<string> v_line;
	ifstream in("main.cpp");
	while (getline(in, line))
		v_line.push_back(line);

	for (int i = 0; i < v_line.size();)
	{
		if (cin.get() == '\n')
		{
			cout << i << ": " << v_line[i];
			i++;
		}
	}
	cout << endl;
	
	//ex2_8
	vector<float> vf1;
	float f1;
	for (int i = 0; i < 7; i++)
	{
		cin >> f1;
		vf1.push_back(f1);
		//ex2_10
		vf1[i] *= vf1[i];
	}

	for (int i = 0; i < vf1.size(); i++)
	{
		cout << vf1[i] << " ";
	}
	cout << endl;

	//ex2_9
	vector<float> vf2;
	float f2;
	for (int i = 0; i < vf1.size(); i++)
	{
		f2 = vf1[i] * 2;
		vf2.push_back(f2);
	}

	for (int i = 0; i < vf1.size(); i++)
	{
		cout << i << ": " << vf1[i] << " " << vf2[i] << endl;
	}


	system("Pause");
	return 0;
}