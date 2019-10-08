//Leetcode 1218

class Solution {
public:
	int longestSubsequence(vector<int> & arr, int difference) {
		unordered_map<int, int> val2num;
		int res = 0;
		for(int i=0;i<arr.size();++i) {
			auto ind = val2num.find(arr[i] - difference);
			if(ind == val2num.end()) {
				val2num[arr[i]] = 1;
				res = max(res, 1);
			}
			else {
				val2num[arr[i]] = max(val2num[arr[i]], ind->second + 1);
				res = max(res, val2num[arr[i]]);
			}
		}
		return res;
	}
};
