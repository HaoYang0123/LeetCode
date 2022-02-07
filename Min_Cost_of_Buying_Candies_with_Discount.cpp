// Leetcode 2144

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());  //从大到小排序
        int res = 0;
        for(int i=0; i<cost.size(); ++i) {
            if(i % 3 == 2) continue;
            res += cost[i];
        }
        return res;
    }
};
