#include<vector>
#include<iostream>
using namespace std;

int subarraysDivByK(vector<int>& A, int K) 
{
	int* record = new int[K]();
	record[0] = 1;
	int answer = 0, sum = 0;
	for (int a : A)
	{
		sum += a;
		//c++的模可以是负数
		int mod = (sum % K + K) % K;
		answer += record[mod];
		++record[mod];
	}

	delete[] record;
	return answer;
}

int main()
{
	vector<int> v1 = { 4,5,0,-2,-3,1 };
	int K1 = 5;

	cout << subarraysDivByK(v1, K1) << endl;


	system("Pause");
	return 0;
}