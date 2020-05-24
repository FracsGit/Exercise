#include<vector>
#include<iostream>
using namespace std;

int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k)
{
	if (i >= int(nums1.size())) return nums2[j + k - 1];//nums1为空数组
	if (j >= int(nums2.size())) return nums1[i + k - 1];//nums2为空数组
	if (k == 1)
	{
		return nums1[i] < nums2[j] ? nums1[i] : nums2[j];
	}
	int midVal1 = (i + k / 2 - 1 < int(nums1.size())) ? nums1[i + k / 2 - 1] : INT32_MAX;
	int midVal2 = (j + k / 2 - 1 < int(nums2.size())) ? nums2[j + k / 2 - 1] : INT32_MAX;
	if (midVal1 < midVal2)
	{
		return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
	}
	else 
	{
		return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
	}
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int m = nums1.size();
	int n = nums2.size();
	int left = (m + n + 1) / 2;
	int right = (m + n + 2) / 2;

	return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
}

int main()
{
	vector<int> nums1 = { 3};
	vector<int> nums2 = { -2, -1, 3, 7, 9, 55 };
	vector<int> nums3 = { 1, 1, 1 };
	vector<int> nums4 = { 1, 1, 1 };
	vector<int> nums5 = { 2 };
	vector<int> nums6 = { 1, 3, 4 };
	vector<int> nums7 = {};
	vector<int> nums8 = { 1, 2 };
	vector<int> nums9 = { 1, 3, 11, 19 };
	vector<int> nums10 = { 2 };
	vector<int> nums11 = { 1, 3 , 88, 99};
	vector<int> nums12 = { 2, 44, 47 };

	cout << findMedianSortedArrays(nums1, nums2) << endl;
	cout << findMedianSortedArrays(nums3, nums4) << endl;
	cout << findMedianSortedArrays(nums5, nums6) << endl;
	cout << findMedianSortedArrays(nums7, nums8) << endl;
	cout << findMedianSortedArrays(nums9, nums10) << endl;
	cout << findMedianSortedArrays(nums11, nums12) << endl;

	system("Pause");
	return 0;
}