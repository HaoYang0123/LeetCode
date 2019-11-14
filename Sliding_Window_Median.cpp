//Leetcode 480
//WA好多次，使用map统计次数的时候，计算median值还是比较麻烦，有很多边界要考虑
//我看网上代码，使用multiset<int>来处理，应该容易许多

class Solution {
public:
	vector<double> medianSlidingWindow(vector<int> & nums, int k) {
		map<int,int> val2num;
		for(int i=0;i<k-1;++i) val2num[nums[i]]++;
		bool is_odd = k % 2;
		int median_k = k / 2; //median position
		vector<double> res;
		for(int i=k-1;i<nums.size();++i) {
			val2num[nums[i]]++;
			auto start_ind = val2num.begin();
			int low = 0, high = 0;
			while(true) {
				high = low + start_ind->second;
				if(low <= median_k && high >= median_k + is_odd) break;
				start_ind++;
				low = high;
			}
			if(is_odd) res.push_back(start_ind->first);
			else {
				if(high == median_k)
					res.push_back(((long long)(start_ind->first)+(long long)((++start_ind)->first)) / 2.0);
				else
					res.push_back(start_ind->first);
			}
			val2num[nums[i-k+1]]--;
			if(val2num[nums[i-k+1]] == 0) val2num.erase(nums[i-k+1]);
		}
		return res;
	}
};
