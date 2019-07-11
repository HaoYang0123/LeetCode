//Leetcode 1094
//与Leetcode 1109 Corporate Flight Bookings  类似，解法一样，使用res来记录起、止的上下车人数
//然后计算res的前缀和就是对应时刻的总人数
//当某时刻的总人数超过capacity，则返回false（表示车的容量无法承受这么多的乘客）;否则返回true

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        vector<int> res(1002,0);
        int max_loc = 0;
        for(int i=0;i<n;++i) {
            res[trips[i][1]] += trips[i][0];
            res[trips[i][2]] -= trips[i][0];
            if(trips[i][2]>max_loc) max_loc = trips[i][2];
        }
        if(res[0] > capacity) return false;
        for(int i=1;i<=max_loc;++i) {
            res[i] += res[i-1];
            if(res[i] > capacity) return false;
        }
        return true;
    }
};
