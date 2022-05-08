// Leetcode 2256

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sum = 0;
        for(int i=0; i<nums.size(); ++i) sum += (long long)(nums[i]);
        long long cur = 0;
        int res_idx = - 1;
        long long min_v = INT_MAX;
        for(int i=0; i<nums.size(); ++i) {
            cur += (long long)(nums[i]);
            long long left = cur / (i+1);
            long long right = 0;
            if(i != nums.size()-1)
                right = (sum - cur) / (nums.size()-1-i);
            long long tmp = abs(left - right);
            if(tmp < min_v) {
                res_idx = i;
                min_v = tmp;
            }
        }
        return res_idx;
    }
};
