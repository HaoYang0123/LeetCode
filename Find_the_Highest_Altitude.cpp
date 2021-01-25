// Leetcode 1732

class Solution {
public:
	int largestAltitude(vector<int>& gain) {
		int res = 0;
		int cur = 0;
		for(int i=0;i<gain.size();++i) {
			cur += gain[i];
			res = max(res, cur);
		}
		return res;
	}
};
