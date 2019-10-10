//Leetcode 1210

class MyPoint {
public:
	int i, j;
	int type;

public:
	MyPoint(int ii, int jj, int tt) : i(ii), j(jj), type(tt) {
	}
};

class Solution {
public:
	int minimumMoves(vector<vector<int>> & grid) {
		int n = grid.size(), m = grid[0].size();
		if(grid[n-1][m-2] == 1 || grid[n-1][m-1] == 1) return -1;
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
		//dp[i][j][0]表示从起点到达(i,j-1)和(i,j)的最小步数（横向）
		//dp[i][j][1]表示从起点到达(i-1,j)和(i,j)的最小步数（纵向）
		queue<pair<MyPoint, int>> qs;
		MyPoint startPoint(0,1,0);
		qs.push(pair<MyPoint,int>(startPoint, 0));
		while(!qs.empty()) {
			pair<MyPoint, int> curP = qs.front();
			qs.pop();
			MyPoint & cur = curP.first;
			int step = curP.second;
			int curI = cur.i, curJ = cur.j, curT = cur.type;
			if(curT == 0) { //横向
				int newJ = curJ + 1;
				if(newJ < m && grid[curI][newJ] == 0) {
					if(dp[curI][newJ][0] > step + 1) {
						dp[curI][newJ][0] = step + 1;
						MyPoint newPoint(curI, newJ, 0);
						qs.push(pair<MyPoint,int>(newPoint, step+1));
					}
				}
				int newI = curI + 1;
				if(newI < n && grid[newI][curJ-1] == 0 && grid[newI][curJ] == 0) {
					if(dp[newI][curJ-1][1] > step + 1) {
						dp[newI][curJ-1][1] = step + 1;
						MyPoint newPoint(newI, curJ-1, 1);
						qs.push(pair<MyPoint,int>(newPoint, step+1));
					}
					if(dp[newI][curJ][0] > step + 1) {
						dp[newI][curJ][0] = step + 1;
						MyPoint newPoint(newI, curJ, 0);
						qs.push(pair<MyPoint,int>(newPoint, step+1));
					}
				}
			}
			else { //纵向
				int newI = curI + 1;
				if(newI < n && grid[newI][curJ] == 0) {
					if(dp[newI][curJ][1] > step + 1) {
						dp[newI][curJ][1] = step + 1;
						MyPoint newPoint(newI, curJ, 1);
						qs.push(pair<MyPoint,int>(newPoint, step+1));
					}
				}
				int newJ = curJ + 1;
				if(newJ < m && grid[curI][newJ] == 0 && grid[curI-1][newJ] == 0) {
					if(dp[curI-1][newJ][0] > step + 1) {
						dp[curI-1][newJ][0] = step + 1;
						MyPoint newPoint(curI-1, newJ, 0);
						qs.push(pair<MyPoint,int>(newPoint, step+1));
					}
					if(dp[curI][newJ][1] > step + 1) {
						dp[curI][newJ][1] = step + 1;
						MyPoint newPoint(curI, newJ, 1);
						qs.push(pair<MyPoint,int>(newPoint, step+1));
					}
				}
			}
		}
		int res = dp[n-1][m-1][0];
		if(res == INT_MAX) return -1;
		return res;
	}
};
