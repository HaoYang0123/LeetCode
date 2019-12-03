//Leetcode 1275

class Solution {
public:
	string tictactoe(vector<vector<int>> & moves) {
		vector<int> X_row(3,0), O_row(3,0);
		vector<int> X_col(3,0), O_col(3,0);
		vector<vector<char>> data(3,vector<char>(3, ' '));
		for(int i=0;i<moves.size();++i) {
			int r=moves[i][0],c=moves[i][1];
			if(i%2 == 0) {
				data[r][c] = 'X';
				X_row[r]++;
				X_col[c]++;
				if(X_row[r] == 3 || X_col[c] == 3) return "A";
				if(data[0][0] == 'X' && data[1][1] == 'X' && data[2][2] == 'X') return "A";
				if(data[0][2] == 'X' && data[1][1] == 'X' && data[2][0] == 'X') return "A";
			}
			else {
				data[r][c] = 'O';
				O_row[r]++;
				O_col[c]++;
				if(O_row[r] == 3 || O_col[c] == 3) return "B";
				if(data[0][0] == 'O' && data[1][1] == 'O' && data[2][2] == 'O') return "B";
				if(data[0][2] == 'O' && data[1][1] == 'O' && data[2][0] == 'O') return "B";
			}
		}
		if(moves.size() == 9) return "Draw";
		return "Pending";
	}
};
