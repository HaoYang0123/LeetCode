// Leetcode 1848

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = INT_MAX;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i] != target) continue;
            res = min(res, abs(start-i));
        }
        return res;
    }
};
