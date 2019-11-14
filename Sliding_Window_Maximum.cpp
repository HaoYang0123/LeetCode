class Solution {
public:
	vector<int> maxSlidingWindow(vector<int> & nums, int k) {
		map<int,int> val2num;
		for(int i=0;i<k-1;++i) val2num[nums[i]]++;
		vector<int> res;
		for(int i=k-1;i<nums.size();++i) {
			val2num[nums[i]]++;
			res.push_back(val2num.rbegin()->first);
			val2num[nums[i-k+1]]--;
			if(val2num[nums[i-k+1]] == 0) val2num.erase(nums[i-k+1]);
		}
		return res;
	}
};
