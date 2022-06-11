// Leetcode 2294

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int cur = nums[0];
        while(true) {
            auto idx = upper_bound(nums.begin(), nums.end(), cur+k);
            ++res;
            if(idx == nums.end()) break;
            cur = *idx;
        }
        return res;
    }
};
