#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

int subarraysDivByK(vector<int>& A, int K) 
{
	unordered_map<int, int> record = { {0, 1} };
	int answer = 0, sum = 0;
	for (int a : A)
	{
		sum += a;
		//c++的模可以是负数
		int mod = (sum % K + K) % K;
		if (record.count(mod))
			answer += record[mod];
		++record[mod];
	}

	return answer;
}

int main()
{
	vector<int> v1 = { -1,-9,-4,0 };
	int K1 = 9;

	cout << subarraysDivByK(v1, K1) << endl;


	system("Pause");
	return 0;
}