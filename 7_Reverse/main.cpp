#include<iostream>
using namespace std;

int reverse(int x) 
{
	int result = 0;
	int overflow = 214748364;


	for (int i = 0;x!=0 && i<9;x/=10,i++)
	{
		result = result * 10 + x % 10;
	}

	if (x != 0)
	{ 
		if (result>overflow || result<-overflow)
		{				
			return 0;
		}
		else if ((result == overflow && x>7) || (result == -overflow && x<-8))
		{
			return 0;
		}
		result = result * 10 + x;
	}

	return result;
}

int main()
{
	int x = 563847412;
	int y = -2147483641;
	int z = 123;
	
	cout << sizeof(int) << endl;
	cout << x << " reverse: " << reverse(x) << endl;
	cout << y << " reverse: " << reverse(y) << endl;
	cout << z << " reverse: " << reverse(z) << endl;
	if (z > y)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	system("Pause");
	return 0;
}
