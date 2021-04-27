// Leetcode 1838
//需要进行排序，所以时间复杂度为O(NlgN)

class Solution {
public:
	int maxFrequency(vector<int>& nums, int k) {
		int res = 1;
		sort(nums.begin(), nums.end());
		int i = 0; //从i至j
		long long cur_sum = 0;
		for (int j = 0; j < nums.size(); ++j) {
			cur_sum += nums[j];
			long long new_sum = (j - i + 1) * (long long)nums[j];
			while (new_sum - cur_sum > k) {  //如果(i,j)的数组转成等于元素都为nums[j]的子数组，需要的步数超过了k，则++i并更新cur_sum
				cur_sum -= nums[i];
				++i;
				new_sum = (j - i + 1) * (long long)nums[j];
			}
			res = max(res, j - i + 1);
		}
		return res;
	}
};
