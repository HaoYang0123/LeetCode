//Leetcode 1262
//动态规划

class Solution {
public:
	int maxSumDivThree(vector<int> & nums) {
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(3,0)); //dp[i][j]表示从0至i，包含nums[i]的最大的求和，余3等于j
		vector<vector<int>> dp2(n, vector<int>(3,0)); //dp2与dp类似，只是从0至i，但不要求包含nums[i]
		dp[0][nums[0]%3] = nums[0];
		dp2[0][nums[0]%3] = nums[0];
		for(int i=1;i<n;++i) {
			int cur_remainder = nums[i] % 3; //当前元素的余数
			dp[i][cur_remainder] = dp2[i-1][0] + nums[i];
			dp2[i][cur_remainder] = max(dp2[i-1][cur_remainder], dp[i][cur_remainder]);
			for(int j=1;j<3;++j) { //之前求和的余数
				int new_remainder = (j+cur_remainder) % 3;
				if(dp2[i-1][j] > 0) {
					dp[i][new_remainder] = dp2[i-1][j] + nums[i];
					dp2[i][new_remainder] = max(dp2[i-1][new_remainder], dp[i][new_remainder]);
				}
				else {
					dp2[i][new_remainder] = dp2[i-1][new_remainder];
				}
			}
		}
		return dp2[n-1][0];
	}
};
