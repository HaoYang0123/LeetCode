//Leetcode 1235
//所有元素，按照end从小到大排序
//dp[i]记录时间截至到i，能够取得的最大利润
//当items[i]时，有两种选择：
//1) 考虑items[i]，那么利润等于profits[i]+dp[<=items[i].start]，其中后一项表示时间截至日期在items[i].start前的最大利润（注：dp是递增的）
//2）不考虑items[i]，那么利润就等于dp中最大的那个利润（最大利润一定是dp中最后一个，因为dp是递增的）
//最终答案即为dp中最后一个

class One_Item {
public:
	int start, end;
	int prof;
public:
	One_Item(int s, int e, int p) : start(s), end(e), prof(p) {
	}
};

bool cmp(const One_Item & a, const One_Item & b) {
	return a.end < b.end;
}

class Solution {
public:
	int jobScheduling(vector<int> & startTime, vector<int> & endTime, vector<int> & profit) {
		vector<One_Item> items;
		for(int i=0;i<startTime.size();++i) {
			items.push_back(One_Item(startTime[i], endTime[i], profit[i]));
		}
		sort(items.begin(), items.end(), cmp);
		map<int, int> dp; //dp[i]表示时间截至到i，能够取得的最大利润
		for(int i=0;i<items.size();++i) {
			int last_end = items[i].start;
			auto ind = dp.upper_bound(last_end);
			int cur_max = items[i].prof; //cur_max表示目前的最大利润
			if(ind != dp.begin()) {
				--ind;
				cur_max += ind->second;
			}
			if(dp.size() > 0) {
				auto ind2 = dp.rbegin();
				cur_max = max(cur_max, ind2->second);
			}
			dp[items[i].end] = cur_max;
		}
		return dp.rbegin()->second;
	}
};
