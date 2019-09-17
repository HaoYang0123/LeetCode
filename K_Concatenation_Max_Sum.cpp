//Leetcode 1191

class Solution {
public:
	int MOD;
	int kConcatenationMaxSum(vector<int> & arr, int k) {
		MOD = 1000000007;
		int max_left = 0, max_right = 0, sum = 0, one_max = 0;
		int cur = 0;
		for(int i=0;i<arr.size();++i) {
			sum += arr[i];
			cur += arr[i];
			if(sum > max_left) max_left = sum;
			if(cur > one_max) one_max = cur;
			if(cur < 0) cur = 0;
		}
		sum = 0;
		for(int i=arr.size()-1;i>=0;--i) {
			sum += arr[i];
			if(sum > max_right) max_right = sum;
		}
		long long sum_k = (long long)(sum) * k;
		if(k <= 1) return one_max;
		long long res = max(sum_k, (long long)max(max_left + max_right, one_max));
		if(k >= 3) res = max(((long long)sum * (k-2) + max_left + max_right), res);
		return res % MOD;
	}
};
