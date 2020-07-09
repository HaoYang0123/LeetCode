//Leetcode 1504
//时间复杂度O(N^3)

class Solution {
public:
	int numSubmat(vector<vector<int>> & mat) {
		int n = mat.size(), m = mat[0].size();
		vector<vector<int>> rlong(n, vector<int>(m, 0)); //rlong[i][j]表示(i,j)向右连续1的个数
		for (int i = 0; i < n; ++i) {
			if (mat[i][m - 1] == 1) rlong[i][m - 1] = 1;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = m - 2; j >= 0; --j) {
				if (mat[i][j] == 1) rlong[i][j] = rlong[i][j + 1] + 1;
			}
		}
		int res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) { //枚举子矩阵的左上角(i,j)
				if (mat[i][j] == 1) {
					int cur_long = rlong[i][j]; //当前位置(i,j)，当前行连续往右走1的个数为rlong[i][j]
					res += cur_long; //则有cur_long个矩阵: 1*1, 1*2,...,1*cur_long
					for (int k = i + 1; k < n; ++k) { //枚举下面行的情况
						if (rlong[k][j] == 0) break; //如果下面行没有1（即mat[k][j]=0），则中断了
						cur_long = min(cur_long, rlong[k][j]); //如果下面行连续往右走1的个数比较小，那么需要将cur_long更新为当前中最小的
						res += cur_long; //比如k=i+1时，子矩阵为：2*1, 2*2,...,2*cur_long
					}
				}
			}
		}
		return res;
	}
};
