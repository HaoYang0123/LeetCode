// Leetcode 1769

class Solution {
public:
	vector<int> minOperations(string boxes) {
		int n = boxes.length();
		vector<int> res(n, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (boxes[j] == '1') {
					res[i] += abs(j - i);
				}
			}
		}
		return res;
	}
};
