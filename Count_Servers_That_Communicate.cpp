//Leetcode 1267
//O(N*M)时间复杂度

class Solution {
public:
	int countServers(vector<vector<int>> & grid) {
		int res = 0;
		int n=grid.size(), m=grid[0].size();
		vector<int> row(n, 0);
		vector<int> col(m, 0);
		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j) {
				row[i] += grid[i][j];
				col[j] += grid[i][j];
			}
		}
		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j) {
				if(grid[i][j]==0) continue;
				if(row[i] == 1 && col[j] == 1) continue;
				res++;
			}
		}
		return res;
	}
};
