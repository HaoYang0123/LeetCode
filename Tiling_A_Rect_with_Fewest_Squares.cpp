//Leetcode 1240

class Solution {
public:
	int final_res;
	int tilingRectangle(int n, int m) {
		vector<int> matrix_row(n, 0); //matrix_row[i]表示第i中为1的数目
		final_res = n * m;
		dfs(matrix_row, 0, n, m);
		return final_res;
	}

	int dfs(vector<int> & matrix_row, int cur_res, int n, int m) {
		if(cur_res >= final_res) return n*m; //剪枝，不然会超时
		int minIndex = 0, minValue = matrix_row[0];
		for(int i=1;i<matrix_row.size(); ++i) {
			if(matrix_row[i] < minValue) {
				minValue = matrix_row[i];
				minIndex = i;
			}
		}
		int max_row = 1;
		for(int i=minIndex+1;i<matrix_row.size();++i) {
			if(matrix_row[i] > minValue) break;
			max_row++;
		}
		int max_colum = m-minValue;
		int max_square = min(max_row, max_colum);
		if(max_square == 0) {
			final_res = min(final_res, cur_res);
			return 0;
		}
		int res = n*m;
		for(int i=max_square;i>=1;--i) {
			//更新matrix_row
			for(int j=0;j<i;++j) {
				matrix_row[minIndex+j] += i;
			}
			int cur = dfs(matrix_row, cur_res+1, n, m);
			res = min(res, cur);
			//复原matrix_row
			for(int j=0;j<i;++j) {
				matrix_row[minIndex+j] -= i;
			}
		}
		return res+1;
	}
};
