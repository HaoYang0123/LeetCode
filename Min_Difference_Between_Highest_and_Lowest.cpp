// Leetcode 1984

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for(int i=0; i<=nums.size()-k; ++i) {
            int dif = nums[i+k-1] - nums[i];
            res = min(res, dif);
        }
        return res;
    }
};
