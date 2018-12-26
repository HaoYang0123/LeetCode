//Leetcode 85

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0 || matrix[0].size() == 0) return 0;
        int n = matrix.size(), m = matrix[0].size();
		vector<vector<int>> mat(n, vector<int>(m, 0));
		for(int i=0;i<m;++i) {
			if(matrix[0][i] == '1') mat[0][i] = 1;
		}
		for(int i=1;i<n;++i) {
			for(int j=0;j<m;++j) {
				if(matrix[i][j] == '1') mat[i][j] = mat[i-1][j] + 1; 
			}
		}
		int res = 0;
		for(int i=0;i<n;++i) {
			int tmp = maximalLine(mat[i]);
			if(tmp > res) res = tmp;
		}
		return res;
    }
	int maximalLine(vector<int> & line) {
		stack<int> sta;
		sta.push(line[0]);
		int res = line[0];
		for(int i=1;i<line.size();++i) {
			if(sta.top() <= line[i]) sta.push(line[i]);
			else {
				int del = 0;
				while(!sta.empty() && sta.top() > line[i]) {
					int cur = sta.top();
					sta.pop();
					++del;
					int tmp = cur*del;
					if(tmp>res) res = tmp;
				}
				for(int j=0;j<=del;++j) sta.push(line[i]);
			}
		}
		int del = 0;
		while(!sta.empty()) {
			int cur = sta.top();
			sta.pop();
			++del;
			int tmp = cur*del;
			if(tmp>res) res = tmp;
		}
		return res;
	}
};

int main() {
	char a[4][5] = {'1','0','1','0','0',
				'1','0','1','1','1',
				'1','1','1','1','1',
				'1','0','0','1','0'};
	vector<vector<char>> data;
	for(int i=0;i<4;++i) {
		vector<char> t;
		for(int j=0;j<5;++j) {
			t.push_back(a[i][j]);
		}
		data.push_back(t);
	}
	Solution s;
	int res = s.maximalRectangle(data);
	return 0;
}
