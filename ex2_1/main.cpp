#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	//ex2_1
	cout << "Hello, I am Fracs.\n"
		<< "I am 101 today." << endl;

	//ex2_2
	double radius, area;
	cout << "Enter the radius of the circle£º" << endl;
	cin >> radius;
	area = 3.14 * radius * radius;
	cout << "The area of the circle is " << area << endl;

	//ex2_3, ex2_4
	ifstream in("main.cpp");
	string word, targetWord;
	int numWord = 0, numTarget = 0;
	cout << "Enter target word." << endl;
	cin >> targetWord;
	while (in >> word)
	{
		numWord++;
		if (word == targetWord)
			numTarget++;
	}
	cout << "There is " << numWord << " words in the file.\n" 
		<< "And " << numTarget << " \"" << targetWord << "\" in the file." << endl;

	//ex2_5
	vector<string> v_line;
	string line;
	ifstream in2_5("main.cpp");
	while (getline(in2_5, line))
		v_line.push_back(line);
	for (int i = v_line.size() - 1; i >= 0; i--)
		cout << i << ": " << v_line[i] << endl;

	//ex2_6
	string wholeFile;
	for (int i = 0; i < v_line.size(); i++)
		wholeFile += v_line[i];
	cout << wholeFile << endl;

	system("Pause");
	return 0;
}