// Leetcode 2099

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> val_and_idx;  //找到top-k个数，然后按在原数组中位置放置这k个数，即可
        for(int i=0; i<nums.size(); ++i) val_and_idx.push_back({nums[i], i});
        sort(val_and_idx.rbegin(), val_and_idx.rend());
        
        vector<pair<int, int>> idx_and_val;
        for(int i=0; i<k; ++i) idx_and_val.push_back({val_and_idx[i].second, val_and_idx[i].first});
        sort(idx_and_val.begin(), idx_and_val.end());
        
        vector<int> res(k, 0);
        for(int i=0; i<k; ++i) res[i] = idx_and_val[i].second;
        return res;
    }
};
