//Leetcode 1277
//O(N^3)时间复杂度

class Solution {
public:
	int countSquares(vector<vector<int>> & matrix) {
		int n=matrix.size(),m=matrix[0].size();
		vector<vector<int>> dp(n,vector<int>(m,0)); //dp[i][j]表示以(i,j)为底，往上走连续1的个数
		for(int i=0;i<m;++i) dp[0][i]=matrix[0][i];
		for(int i=1;i<n;++i) {
			for(int j=0;j<m;++j) {
				if(matrix[i][j]==1) dp[i][j]=1+dp[i-1][j];
			}
		}
		int res = 0;
		for(int i=0;i<n;++i) {
			vector<int> & one_row = dp[i];
			for(int j=0;j<m;++j) {
				if(matrix[i][j] == 0) continue;
				int min_height = one_row[j];
				int k=j+1;
				for(;k<m;++k) {
					if(k-j+1>min_height) break;
					min_height = min(min_height, one_row[k]);
					if(k-j+1>min_height) break;
				}
				int max_side = (k-j);
				res += max_side;
			}
		}
		return res;
	}
};
