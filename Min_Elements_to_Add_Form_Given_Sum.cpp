// Leetcode 1785

class Solution {
public:
	int minElements(vector<int>& nums, int limit, int goal) {
		long long cur_sum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			cur_sum += (long long)(nums[i]);
		}
		long long need = abs((long long)(goal) - cur_sum);
		if (need == 0) return 0;
		return (need - 1) / limit + 1;
	}
};
