// Leetcode 1877

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i=0; i<nums.size()/2; ++i) {
            res = max(res, nums[i] + nums[nums.size()-1-i]);
        }
        return res;
    }
};
