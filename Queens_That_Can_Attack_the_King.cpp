//Leetcode 1222

class Solution {
public:
	vector<vector<int>> queensAttacktheKing(vector<vector<int>> & queens, vector<int> & king) {
		int ki = king[0], kj = king[1];
		vector<vector<int>> grid(8, vector<int>(8, 0));
		for(int i=0;i<queens.size();++i) {
			int curi = queens[i][0], curj = queens[i][1];
			grid[curi][curj] = 1;
		}
		vector<vector<int>> res;
		//向左
		int newJ = kj - 1;
		while(newJ >= 0) {
			if(grid[ki][newJ] == 1) {
				vector<int> tmp(2, 0); tmp[0] = ki; tmp[1] = newJ;
				res.push_back(tmp);
				break;
			}
			--newJ;
		}
		//向右
		newJ = kj + 1;
		while(newJ < 8) {
			if(grid[ki][newJ] == 1) {
				vector<int> tmp(2, 0); tmp[0] = ki; tmp[1] = newJ;
				res.push_back(tmp);
				break;
			}
			++newJ;
		}
		//向上
		int newI = ki - 1;
		while(newI >= 0) {
			if(grid[newI][kj] == 1) {
				vector<int> tmp(2, 0); tmp[0] = newI; tmp[1] = kj;
				res.push_back(tmp);
				break;
			}
			--newI;
		}
		//向下
		newI = ki + 1;
		while(newI < 8) {
			if(grid[newI][kj] == 1) {
				vector<int> tmp(2, 0); tmp[0] = newI; tmp[1] = kj;
				res.push_back(tmp);
				break;
			}
			++newI;
		}
		//向左上
		newI = ki - 1; newJ = kj - 1;
		while(newI >= 0 && newJ >= 0) {
			if(grid[newI][newJ] == 1) {
				vector<int> tmp(2, 0); tmp[0] = newI; tmp[1] = newJ;
				res.push_back(tmp);
				break;
			}
			--newI; --newJ;
		}
		//向右下
		newI = ki + 1; newJ = kj + 1;
		while(newI < 8 && newJ < 8) {
			if(grid[newI][newJ] == 1) {
				vector<int> tmp(2, 0); tmp[0] = newI; tmp[1] = newJ;
				res.push_back(tmp);
				break;
			}
			++newI; ++newJ;
		}
		//向右上
		newI = ki - 1; newJ = kj + 1;
		while(newI >= 0 && newJ < 8) {
			if(grid[newI][newJ] == 1) {
				vector<int> tmp(2, 0); tmp[0] = newI; tmp[1] = newJ;
				res.push_back(tmp);
				break;
			}
			--newI; ++newJ;
		}
		//向左下
		newI = ki + 1; newJ = kj - 1;
		while(newI < 8 && newJ >= 0) {
			if(grid[newI][newJ] == 1) {
				vector<int> tmp(2, 0); tmp[0] = newI; tmp[1] = newJ;
				res.push_back(tmp);
				break;
			}
			++newI; --newJ;
		}
		return res;
	}
};
