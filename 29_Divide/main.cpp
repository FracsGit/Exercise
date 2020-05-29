#include<iostream>
using namespace std;

int FindBit(int x)
{
	int i = 0;
	while (x > 0)
	{
		x >>=1;
		++i;
	}
	return i;
}

int divide(int dividend, int divisor) 
{
	if (divisor == 0)
		return 0;
	if (dividend == 0)
		return 0;
	if (divisor == INT32_MIN)
	{
		if (dividend == INT32_MIN)
			return 1;
		else
			return 0;
	}
	bool isMin = false;
	if (dividend == INT32_MIN)
	{
		if (divisor == 1)
			return dividend;
		else if (divisor == -1)
			return INT32_MAX;
		isMin = true;
	}

	bool positive = true;
	if (dividend < 0)
	{
		positive = !positive;
		if (dividend == INT32_MIN)
			dividend = INT32_MAX;
		else
			dividend = 0 - dividend;
	}
	if (divisor < 0)
	{
		positive = !positive;
		divisor = 0 - divisor;
	}

	if (dividend < divisor)
		return 0;

	int i = FindBit(dividend);
	int j = FindBit(divisor);

	int result = 0;

	int turn = i - j;
	divisor = divisor << turn;

	if (isMin)
	{
		dividend -= divisor;
		++result;
		++dividend;
		if (dividend == divisor)
		{
			dividend -= divisor;
			++result;
		}

		if(turn > 0)
		{
			divisor = divisor >> 1;
			result = result << 1;
			--turn;
		}		
	}

	while (turn > 0 && dividend > 0)
	{
		if (dividend >= divisor)
		{
			dividend -= divisor;
			++result;
		}
		divisor = divisor >> 1;
		result = result << 1;
		--turn;
	}

	if (turn == 0 && dividend != 0)
	{
		if (dividend >= divisor)
		{
			dividend -= divisor;
			++result;
		}
	}
	else
		result = result << turn;

	if (positive)
		return result;
	else
		return 0 - result;
}

int main()
{
	cout << divide(10, 3) << endl;
	cout << divide(7, -3) << endl;
	cout << divide(0, 3) << endl;
	cout << divide(7, 0) << endl;
	cout << divide(0, 0) << endl;
	cout << divide(7, 14) << endl;
	cout << divide(18957, 21) << endl;
	cout << divide(-58999, 14) << endl;
	cout << INT32_MAX << endl;
	cout << INT32_MIN << endl;
	cout << divide(INT32_MIN, 1) << endl;
	cout << divide(INT32_MIN, -1) << endl;
	cout << divide(INT32_MAX, 1) << endl;
	cout << divide(INT32_MAX, -1) << endl;
	cout << divide(INT32_MIN, INT32_MIN) << endl;
	cout << divide(INT32_MIN, INT32_MAX) << endl;
	cout << divide(INT32_MAX, INT32_MIN) << endl;
	cout << divide(INT32_MAX, INT32_MAX) << endl;
	cout << divide(INT32_MIN, 2) << endl;
	cout << divide(7, 7) << endl;
	cout << divide(-6, -6) << endl;
	cout << divide(INT32_MIN, -1109186033) << endl;

	system("Pause");
	return 0;
}