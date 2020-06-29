#include "S_215_FindKthLargest.h"

S_215_FindKthLargest::S_215_FindKthLargest()
{
}

S_215_FindKthLargest::~S_215_FindKthLargest()
{
}

int S_215_FindKthLargest::findKthLargest(vector<int>& nums, int k)
{
	sort(nums.begin(), nums.end());
	return nums[nums.size() - k];
}