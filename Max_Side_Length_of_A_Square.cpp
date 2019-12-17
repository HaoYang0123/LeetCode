//Leetcode 1292
//时间复杂度有些高:O(N^3logN)
//应该有O(N^2logN)的算法，将所有累积和记录下来

class Solution {
public:
	int maxSideLength(vector<vector<int>> & mat, int threshold) {
		int n = mat.size(), m = mat[0].size();
		int res = 0;
		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j) {
				if(mat[i][j] > threshold) continue;
				int max_side = min(i,j)+1;
				int min_side = 1;
				if(max_side <= res) continue;
				while(min_side <= max_side) {
					int mid_side = (min_side + max_side) / 2;
					bool flag = is_sum_ok(mat, i, j, mid_side, threshold);
					if(flag) {
						res = max(res, mid_side);
						min_side = mid_side + 1;
					}
					else max_side = mid_side - 1;
				}
			}
		}
		return res;
	}

	inline bool is_sum_ok(vector<vector<int>> & mat, int i, int j, int s, int t) {
		int res = 0;
		for(int r=i;r>i-s;--r) {
			for(int c=j;c>j-s;--c) {
				res += mat[r][c];
				if(res > t) return false;
			}
		}
		return true;
	}
};
