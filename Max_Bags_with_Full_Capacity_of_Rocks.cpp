// Leetcode 2279

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> remain(n, 0);
        for(int i=0; i<n; ++i) remain[i] = capacity[i] - rocks[i];
        sort(remain.begin(), remain.end());  //贪心策略，先装剩余最小的桶
        int res = 0;
        for(int i=0; i<n; ++i) {
            if(additionalRocks < remain[i]) break;
            ++res;
            additionalRocks -= remain[i];
        }
        return res;
    }
};
