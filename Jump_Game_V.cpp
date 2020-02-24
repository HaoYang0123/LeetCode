//Leetcode 1340

class Solution {
public:
	int maxJumps(vector<int>& arr, int d) {
		int n = arr.size();
		vector<int> dp(n, -1); //dp[i]表示从i位置出发，能够跳跃多少次
		int max_count = -1, max_index = -1;
		for (int i = 0; i < n; ++i) {
			int tmp = dfs(arr, dp, d, i);
			//cout<<"T\t"<<i<<"\t"<<tmp<<endl;
			if (tmp > max_count) {
				max_count = tmp;
				max_index = i;
			}
		}
		//for(int i=0;i<n;++i) cout<<i<<'\t'<<dp[i]<<endl;
		return max_count + 1;
	}

	int dfs(vector<int> & arr, vector<int> & dp, int d, int start) {
		if (dp[start] != -1) return dp[start];
		int res = -1;
		for (int k = 1; k <= d; ++k) {
			if (start - k < 0 || arr[start - k] >= arr[start]) break; //如果从start往左边跳跃，如果左边高度超过了当前高度，则不能继续往左
			res = max(res, dfs(arr, dp, d, start - k));
		}
		
		
		for (int k = 1; k <= d; ++k) {
			if (start + k >= arr.size() || arr[start + k] >= arr[start]) break; //同样，往右边跳跃也是如此
			res = max(res, dfs(arr, dp, d, start + k));
		}
		dp[start] = res + 1;
		return res + 1;
	}
};
