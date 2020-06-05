#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
	if (matrix.size() == 0 || matrix[0].size() == 0) 
		return {};

	int rows = matrix.size(), columns = matrix[0].size();
	vector<int> order;
	int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
	while (left <= right && top <= bottom) 
	{
		for (int column = left; column <= right; column++) 
			order.push_back(matrix[top][column]);
		for (int row = top + 1; row <= bottom; row++) 
			order.push_back(matrix[row][right]);
		if (left < right && top < bottom) 
		{
			for (int column = right - 1; column > left; column--) 
				order.push_back(matrix[bottom][column]);
			for (int row = bottom; row > top; row--) 
				order.push_back(matrix[row][left]);
		}
		left++;
		right--;
		top++;
		bottom--;
	}
	return order;
}

int main()
{
	vector<vector<int>> v1 = { {1,2,3},{4,5,6},{7,8,9} };
	vector<vector<int>> v2 = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	vector<vector<int>> v3 = { {1,2,3,4} };
	vector<vector<int>> v4 = {  };
	vector<vector<int>> v5 = { {},{},{} };
	vector<vector<int>> v6 = { {1},{5},{9} };

	vector<int> answer;
	answer = spiralOrder(v1);
	for (int num : answer)
		cout << num;
	cout << endl;
	answer = spiralOrder(v2);
	for (int num : answer)
		cout << num;
	cout << endl;
	answer = spiralOrder(v3);
	for (int num : answer)
		cout << num;
	cout << endl;
	answer = spiralOrder(v4);
	for (int num : answer)
		cout << num;
	cout << endl;
	answer = spiralOrder(v5);
	for (int num : answer)
		cout << num;
	cout << endl;
	answer = spiralOrder(v6);
	for (int num : answer)
		cout << num;
	cout << endl;

	system("Pause");
	return 0;
}