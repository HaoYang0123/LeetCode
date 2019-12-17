//Leetcode 1288

class Solution {
public:
	int removeCoveredIntervals(vector<vector<int>> & intervals) {
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> res;
		if(intervals.size() == 0) return 0;
		res.push_back(intervals[0]);
		for(int i = 1; i < intervals.size(); ++i) {
			if(intervals[i][0] >= res.back()[0] && intervals[i][1] <= res.back()[1]) continue;
			res.push_back(intervals[i]);
		}
		return res.size();
	}
};
