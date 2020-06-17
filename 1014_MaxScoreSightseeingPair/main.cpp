#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int maxScoreSightseeingPair(vector<int>& A) 
{
	int size = A.size();
	int leftMax = 0, score = 0;
	for (int i = 1; i < size; ++i)
	{
		leftMax = max(--leftMax, A[i - 1] - 1);
		score = max(score, leftMax + A[i]);
	}

	return score;
}

int main()
{
	vector<int> v1 = { 8,1,5,2,6 };
	cout << maxScoreSightseeingPair(v1) << endl;

	system("Pause");
	return 0;
}