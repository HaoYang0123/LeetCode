//Leetcode 1253

class Solution {
public:
	vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> & colsum) {
		int n = colsum.size(), new_n = n;
		for(int i=0;i<n;++i) {
			if(colsum[i] == 2) {
				--upper;
				--lower;
				--new_n;
			}
			else if(colsum[i] == 0) {
				--new_n;
			}
		}
		if(new_n != upper+lower || upper < 0 || lower < 0) return vector<vector<int>>();
		vector<vector<int>> res(2, vector<int>(n,0));
		for(int i=0;i<n;++i) {
			if(colsum[i] == 2) {
				res[0][i] = 1;
				res[1][i] = 1;
			}
			else if(colsum[i] == 1) {
				if(upper > 0) {
					res[0][i] = 1;
					--upper;
				}
				else res[1][i] = 1;
			}
		}
		return res;
	}
};
