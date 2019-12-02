//Leetcode 1272

class Solution {
public:
	vector<vector<int>> removeInterval(vector<vector<int>> & intervals, vector<int> & toBeRemoved) {
		int n=intervals.size();
		int s = toBeRemoved[0], e = toBeRemoved[1];
		vector<vector<int>> res;
		int i=0;
		for(;i<n;++i) {
			if(intervals[i][0] >= e) break;
			if(intervals[i][1] <= s) {
				res.push_back(intervals[i]);
				continue;
			}
			if(intervals[i][0] >= s && intervals[i][1] <= e) continue;
			else if(intervals[i][0] >= s) {
				intervals[i][0] = e;
				res.push_back(intervals[i]);
			}
			else if(intervals[i][1] <= e) {
				intervals[i][1] = s;
				res.push_back(intervals[i]);
			}
			else {
				vector<int> tmp(2, 0);
				tmp[0] = intervals[i][0]; tmp[1] = s;
				res.push_back(tmp);
				vector<int> tmp2(2, 0);
				tmp2[0] = e; tmp2[1] = intervals[i][1];
				res.push_back(tmp2);
			}
		}
		for(;i<n;++i) res.push_back(intervals[i]);
		return res;
	}
};
