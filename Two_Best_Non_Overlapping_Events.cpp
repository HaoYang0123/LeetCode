// Leetcode 2054

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int res = 0;
        int n = events.size();
        sort(events.begin(), events.end());  //按照startTime从小到大排序
        map<int, int> start2vals;  //start2vals[i]表示从i开始（可能是>i开始的）中的最大值
        //【注】：start2vals一定是递减的，因为用的是cur_max
        //即：start2vals[i] >= start2vals[j] if i<j
        int cur_max = 0;
        for(int i=n-1; i>=0; --i){
            cur_max = max(cur_max, events[i][2]);
            start2vals[events[i][0]] = cur_max;
            res = max(res, events[i][2]);  //选择一个event中最大的值
        }
        for(int i=0; i<n; ++i) {  //枚举选择两个event中最大值
            int cur_end = events[i][1];
            int cur_val = events[i][2];
            //找到第一个比cur_end大的startTime，即为所求，因为第一个比cur_end大的startTime，一定是不重叠的pair，且一定是最大的（因为start2vals是递减的）
            auto idx = start2vals.upper_bound(cur_end);
            if(idx == start2vals.end()) continue;  //没找到pair，则continue
            int pair_val = idx->second;  //idx->second就是成对的value值
            res = max(res, cur_val + pair_val);
        }
        return res;
    }
};
