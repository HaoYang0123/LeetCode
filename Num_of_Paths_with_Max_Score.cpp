//Leetcode 1301
//动态规划：dp[i][j] = max(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])+board[i][j]

class Solution {
public:
	int MOD;
	vector<int> pathsWithMaxScore(vector<string> & board) {
		MOD = 1000000007;
		int n=board.size();
		vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2,INT_MIN))); //dp[i][j]表示从(i,j)走到(0,0)的最大获利值及路径数量
		dp[0][0][0] = 0;
		dp[0][0][1] = 1;
		vector<long long> tmp = dfs(board, n-1, n-1, dp);
		vector<int> res(2,0); res[0] = tmp[0]; res[1] = tmp[1];
		return res;
	}

	vector<long long> dfs(vector<string> & board, int i, int j, vector<vector<vector<long long>>> & dp) {
		if(dp[i][j][0] != INT_MIN) return dp[i][j];
		int r_step[] = {0,-1,-1};
		int c_step[] = {-1,0,-1};
		vector<vector<long long>> prev_res;
		int max_v = INT_MIN;
		for(int k=0;k<3;++k) {
			int newi = i + r_step[k];
			int newj = j + c_step[k];
			if(newi < 0 || newj < 0) continue;
			if(board[i][j] == 'X') continue;
			vector<long long> tmp = dfs(board, newi, newj, dp);
			prev_res.push_back(tmp);
			max_v = max(max_v, int(tmp[0]));
		}
		if(max_v == INT_MIN) {
			dp[i][j][0] = 0;
			dp[i][j][1] = 0;
			return dp[i][j];
		}
		long long path_num = 0;
		for(int i=0;i<prev_res.size();++i) {
			if(prev_res[i][0] == max_v) path_num = (path_num + prev_res[i][1]) % MOD;
		}
		int cur_v = 0;
		if(board[i][j] != 'E' && board[i][j] != 'S') cur_v = int(board[i][j] - '0');
		dp[i][j][0] = path_num > 0 ? max_v + cur_v : 0;
		dp[i][j][1] = path_num;
		return dp[i][j];
	}
};
