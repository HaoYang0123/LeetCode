//Leetcode 1293

class Solution {
public:
	int n,m;
	int shortestPath(vector<vector<int>> & grid, int k) {
		n=grid.size();
		m=grid[0].size();
		vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1, -1)));
		vector<vector<vector<bool>>> is_vis(n, vector<vector<bool>>(m, vector<bool>(k+1, false)));
		//for(int i=0;i<=k;++i) dp[n-1][m-1][i] = 0;
		dp[n-1][m-1][0] = 0;
		//dfs(grid,0,n-1,m-2,dp,is_vis);
		int res = INT_MAX;
		for(int i=0;i<=k;++i) {
			is_vis[0][0][i] = true;
			res = min(res, dfs(grid, i, 0, 0, dp, is_vis));
		}
		if(res == INT_MAX) return -1;
		return res;
	}

	int dfs(vector<vector<int>> & grid, int k, int i, int j, vector<vector<vector<int>>> & dp, vector<vector<vector<bool>>> & is_vis) {
		//if(i==3 && j==2 && k==1) 
		//	cout<<"OOOOO"<<endl;
		if(dp[i][j][k] != -1) return dp[i][j][k];
		int r_step[] = {0,0,-1,1};
		int c_step[] = {-1,1,0,0};
		int res = INT_MAX;
		int k_flag = 0;
		if(grid[i][j] == 1) k_flag = 1;
		for(int p=0;p<4;++p) {
			int new_i = i + r_step[p];
			int new_j = j + c_step[p];
			if(new_i < 0 || new_i >= n) continue;
			if(new_j < 0 || new_j >= m) continue;
			if(k-k_flag < 0) continue;
			if(is_vis[new_i][new_j][k-k_flag]) continue;
			is_vis[new_i][new_j][k-k_flag] = true;
			res = min(res, dfs(grid, k-k_flag, new_i, new_j, dp, is_vis)); 
			is_vis[new_i][new_j][k-k_flag] = false;
		}
		//if(i==3 && j==2 && k==1) 
		//	cout<<"OOOOO"<<endl;
		if(res != INT_MAX) ++res;
		dp[i][j][k] = res;
		return dp[i][j][k];
	}
};
