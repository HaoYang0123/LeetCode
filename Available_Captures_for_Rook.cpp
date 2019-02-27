//Leetcode 999

class Solution {
public:
	int numRookCaptures(vector<vector<char>>& board) {
		int res = 0;
		int a = -1, b = -1;
		for(int i=0;i<8;++i) {
			for(int j=0;j<8;++j) {
				if(board[i][j]=='R') {
					a = i;
					b = j;
					break;
				}
			}
		}
		//向上走
		int a2 = a - 1;
		while(a2>=0) {
			if(board[a2][b] == 'p') {
				++res;
				break;
			}
			else if(board[a2][b] == 'B') break;
			--a2;
		}
		//向下走
		a2 = a + 1;
		while(a2<8) {
			if(board[a2][b] == 'p') {
				++res;
				break;
			}
			else if(board[a2][b] == 'B') break;
			++a2;
		}
		//向左走
		int b2 = b - 1;
		while(b2>=0) {
			if(board[a][b2] == 'p') {
				++res;
				break;
			}
			else if(board[a][b2] == 'B') break;
			--b2;
		}
		//向右走
		b2 = b + 1;
		while(b2<8) {
			if(board[a][b2] == 'p') {
				++res;
				break;
			}
			else if(board[a][b2] == 'B') break;
			++b2;
		}
		return res;
	}
};
