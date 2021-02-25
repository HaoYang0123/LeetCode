// Leetcode 1764

class Solution {
public:
	bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
		//groups = [[1,-1,-1],[3,-2,0]], nums = [1,-1,0,1,-1,-1,3,-2,0]
		int gi = 0, ni = 0;
		for (; ni < nums.size(); ++ni) {
			if (get_one_group(groups[gi], nums, ni)) {
				ni += (groups[gi].size() - 1);
				++gi;
				if (gi >= groups.size()) return true;
			}
		}
		return false;
	}

	inline bool get_one_group(vector<int> & one_group, vector<int> & nums, int ni) {
		for (int oi = 0; oi < one_group.size(); ++oi) {
			if (ni + oi >= nums.size())  return false;
			if (one_group[oi] != nums[ni + oi]) return false;
		}
		return true;
	}
};
