//Leetcode 363
//O(N^3)的时间复杂度，与在矩阵中找子矩阵求和最大类似，只是多了一个限制（和得<=K）
//同样枚举行i和行j，计算(i,j)得到的一维数组，在一维数组中计算和<=K的最大的子数组
//计算一维数组的前缀和，记录到set中，这样当前前缀和如果是cur，那么可以在set中找>=cur-K的最小值
//如果找到了，那么当前最大的<=K的值必然就是cur-(*ind)

class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int K) {
		int res = INT_MIN;
		int n = matrix.size(), m = matrix[0].size();
		for(int i=0;i<n;++i) {
			vector<int> one_data(m, 0);
			for(int j=i;j<n;++j) {
				for(int k=0;k<m;++k) one_data[k] += matrix[j][k];
				int cur = 0, cur_max = INT_MIN;
				for(int k=0;k<m;++k) {
					cur += one_data[k];
					cur_max = max(cur_max, cur);
					if(cur < 0) cur = 0;
				}
				if(cur_max <= K) res = max(res, cur_max);
				else {
					cur_max = INT_MIN;
					cur = 0;
					set<int> ss; //ss存储了当前的前缀和
					ss.insert(0);
					for(int k=0;k<m;++k) {
						cur += one_data[k];
						int v = cur - K;
						auto ind = lower_bound(ss.begin(), ss.end(), v); //在ss中找到>=cur-K的最小值，那么中间一段肯定是<=K的最大值
						if(ind != ss.end())
							cur_max = max(cur_max, cur - (*ind));
						ss.insert(cur);
					}
					res = max(res, cur_max);
				}
			}
		}
		return res;
	}
};
