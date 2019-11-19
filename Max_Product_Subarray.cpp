//Leetcode 152
//这道题里面的陷阱样例有些多

class Solution {
public:
	int maxProduct(vector<int> & nums) {
		int n = nums.size();
		if(n == 1) return nums[0];
		vector<int> neg_num(n, 0); //neg_num[i]表示从0至i之间负数的个数
		vector<int> zero_arr, neg_arr; //zero_arr存储为0的索引, neg_arr存储为负数的索引
		vector<long long> dp(n, 0); //dp[i]表示从0至i的累积乘
		int cur_neg_num = 0, cur_pro = 1;
		for(int i=0;i<n;++i) {
			cur_pro *= nums[i];
			dp[i] = cur_pro;
			if(nums[i] < 0) {
				++cur_neg_num;
				neg_arr.push_back(i);
			}
			else if(nums[i] == 0) zero_arr.push_back(i);
			neg_num[i] = cur_neg_num;
		}
		if(zero_arr.size() == 0) { //如果数组中没有0元素
			if(neg_arr.size() % 2 == 0) //如果负数是偶数个，那么所有元素乘是最大的
				return dp[n-1];
			else //如果负数是奇数个，比如[s1, s2, s3]（s1-3分别三个负数对应于数组中的索引位置）
				//那么最大的结果是[s1+1,n-1]的累积乘与[0,s3-1]的累积乘中较大者
				if(neg_arr[neg_arr.size()-1]<1) return dp[n-1]/dp[neg_arr[0]];
				return max(dp[neg_arr[neg_arr.size()-1]-1], dp[n-1]/dp[neg_arr[0]]);
		}
		//如果数组中有0元素，由于存在0元素的干扰，dp已经不能使用
		//比如有0的位置有[z1, z2, z3]，那么需要在[0,z1-1], [z1+1,z2-1], [z2+1, z3-1], [z3+1,n-1]中找到最大的
		zero_arr.push_back(n);
		long long res = INT_MIN;
		int cur_start = 0;
		for(int i=0;i<zero_arr.size();++i) {
			int cur_end = zero_arr[i]-1;
			if(cur_start == cur_end) {
				res = max(res, (long long)nums[cur_start]);
				cur_start = zero_arr[i]+1;
				continue;
			}
			else if(cur_start > cur_end) {
				cur_start = zero_arr[i]+1;
				continue;
			}
			int prev_neg_num = 0;
			if(cur_start > 0) prev_neg_num = neg_num[cur_start - 1];
			int cur_neg_num = neg_num[cur_end] - prev_neg_num; //cur_neg_num表示在[cur_start, cur_end]中间出现的负数数量
			if(cur_neg_num % 2 == 0) {
				long long cur_res = 1;
				for(int j = cur_start; j <= cur_end; ++j) cur_res *= nums[j];
				res = max(res, cur_res);
			}
			else {
				auto first_neg = lower_bound(neg_arr.begin(), neg_arr.end(), cur_start); //找到第1个>=cur_start的负数的索引位置
				auto end_neg = upper_bound(neg_arr.begin(), neg_arr.end(), cur_end); //找到最后1个<=cur_end的负数的索引位置
				--end_neg;
				long long cur_res1 = 1, cur_res2 = 1;
				for(int j = *first_neg + 1; j <= cur_end; ++j) cur_res1 *= nums[j];
				for(int j = cur_start; j <= *end_neg - 1; ++j) cur_res2 *= nums[j];
				res = max(res, max(cur_res1, cur_res2));
			}
			cur_start = zero_arr[i]+1;
		}
		res = max(res, (long long)0);
		return res;
	}
};
