#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	cout << "Hello, I am Fracs.\n"
		<< "I am 101 today." << endl;

	double radius, area;
	cout << "Enter the radius of the circle£º" << endl;
	cin >> radius;
	area = 3.14 * radius * radius;
	cout << "The area of the circle is " << area << endl;

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


	system("Pause");
	return 0;
}