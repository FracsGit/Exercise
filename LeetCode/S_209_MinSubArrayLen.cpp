#include "S_209_MinSubArrayLen.h"

S_209_MinSubArrayLen::S_209_MinSubArrayLen()
{
}

S_209_MinSubArrayLen::~S_209_MinSubArrayLen()
{
}

int S_209_MinSubArrayLen::minSubArrayLen(int s, vector<int>& nums)
{
	int sum = 0, result = INT32_MAX;
	for (size_t l = 0, r = 0; r < nums.size(); ++r)
	{
		sum += nums[r];
		while (sum >= s && l <= r)
		{
			int tempLength = r - l + 1;
			result = min(result, tempLength);
			sum -= nums[l];
			++l;
		}
	}
	return result == INT32_MAX ? 0 : result;
}