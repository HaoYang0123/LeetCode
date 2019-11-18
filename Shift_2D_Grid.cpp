//Leetcode 1260

class Solution {
public:
	vector<vector<int>> shiftGrid(vector<vector<int>> & grid, int k) {
		int n=grid.size(), m=grid[0].size();
		vector<vector<int>> res(n, vector<int>(m,0));
		int num=n*m;
		vector<int> one_array(num, 0);
		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j) {
				one_array[(i*m+j+k)%num] = grid[i][j];
			}
		}
		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j) {
				res[i][j] = one_array[i*m+j];
			}
		}
		return res;
	}
};
