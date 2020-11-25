//Leetcode 1664
//记录从左往右走的和(只记录偶数情况)：dp[0]=nums[0], dp[2]=nums[0]+nums[2], ...
//记录从右往左走的和(也只记录偶数情况，注：分情况考虑nums当前的长度是偶数和奇数)：如果当前nums是偶数，那么删除某个元素后，第1个元素必然和最后1个元素在同一个域中
//则计算dp2[n-1]=nums[n-1], dp2[n-3]=nums[n-1]+nums[n-3], ...
//最后，枚举0至(n-1)位置作为删除位置，也分奇偶情况，来计算删除后的数据：偶数索引位置求和，是否与奇数索引位置求和相等

class Solution {
public:
	int waysToMakeFair(vector<int> & nums) {
		int sum = 0, n = nums.size();
		if (n == 1) return 1;
		vector<int> dp(n, 0), dp2(n, 0);
		int cur_s = 0;
		for (int i = 0; i < n; ++i) {
			sum += nums[i];
			if (i % 2 == 0) {
				cur_s += nums[i];
				dp[i] = cur_s;
			}
		}
		int end = n - 1;
		if (n % 2 == 1) end = n - 2;
		cur_s = 0;
		for (; end >= 0; end -= 2) {
			cur_s += nums[end];
			dp2[end] = cur_s;
		}
		int res = 0;
		for (int del_idx = 0; del_idx < n; ++del_idx) {
			if(del_idx % 2 == 1) {
				int l = 0, r = 0;
				if (del_idx - 1 >= 0) l = dp[del_idx - 1];
				if (del_idx + 2 < n) r = dp2[del_idx + 2];
				int one = l + r;
				int two = sum - one - nums[del_idx];
				if (one == two) ++res;
			}
			else {
				int l = 0, r = 0;
				if (del_idx - 2 >= 0) l = dp[del_idx - 2];
				if (del_idx + 1 < n) r = dp2[del_idx + 1];
				int one = l + r;
				int two = sum - one - nums[del_idx];
				if (one == two) ++res;
			}
		}
		return res;
	}
};
