// Leetcode 1791

class Solution {
public:
	int findCenter(vector<vector<int>>& edges) {
		int n = edges.size() + 1;
		vector<int> nodes(n + 1, 0);
		for (int i = 0; i < edges.size(); ++i) {
			++nodes[edges[i][0]];
			++nodes[edges[i][1]];
		}
		for (int i = 1; i < n + 1; ++i) {
			if (nodes[i] == n - 1) return i;
		}
		return 0;
	}
};
