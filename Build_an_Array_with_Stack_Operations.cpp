//Leetcode 1441

class Solution {
public:
	vector<string> buildArray(vector<int> & target, int n) {
		unordered_set<int> ss;
		for (auto t : target) ss.insert(t);
		vector<string> res;
		for (int i = 1; i <= n; ++i) {
			if (i > target.back()) break;
			if (ss.find(i) == ss.end()) {
				res.push_back("Push");
				res.push_back("Pop");
			}
			else {
				res.push_back("Push");
			}
		}
		return res;
	}
};
