//Leetcode 1296

class Solution {
public:
	bool isPossibleDivide(vector<int> & nums, int k) {
		if(nums.size() % k != 0) return false;
		multiset<int> ss;
		for(int i=0;i<nums.size();++i) ss.insert(nums[i]);
		while(!ss.empty()) {
			int min_v = *ss.begin();
			for(int v=min_v; v<min_v+k; ++v) {
				auto ind = ss.find(v);
				if(ind == ss.end()) return false;
				ss.erase(ind);
			}
		}
		return true;
	}
};
