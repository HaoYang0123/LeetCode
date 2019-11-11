//Leetcode 1252

class Solution {
public:
	int oddCells(int n, int m, vector<vector<int>> & indices) {
		vector<int> row_data(n,0), col_data(m,0);
		for(int i=0;i<indices.size();++i) {
			row_data[indices[i][0]]++;
			col_data[indices[i][1]]++;
		}
		int res=0;
		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j) {
				int d = row_data[i]+col_data[j];
				if(d%2==1) ++res;
			}
		}
		return res;
	}
};
