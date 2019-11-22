//Leetcode 376
//O(N)时间复杂度

class Solution {
public:
	int wiggleMaxLength(vector<int> & nums) {
		int n = nums.size();
		if(n<=1) return n;
		int flag = 0; //1表示上升，2表示下降
		int i=0;
		while(i<n-1 && nums[i]==nums[i+1]) ++i;
		if(i >= n-1) return 1; //nums中所有元素相同
		if(nums[i]<nums[i+1]) flag = 1;
		else flag = 2;
		++i;
		int res = 2;
		for(;i<n-1;++i) {
			if(nums[i]==nums[i+1]) continue;
			if(nums[i]<nums[i+1] && flag == 2) {
				flag = 1;
				++res;
			}
			else if(nums[i]>nums[i+1] && flag == 1) {
				flag = 2;
				++res;
			}
		}
		return res;
	}
};
