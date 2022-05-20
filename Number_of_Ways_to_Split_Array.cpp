// Leetcode 2270

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        for(int i=0; i<nums.size(); ++i) sum += (long long)(nums[i]);
        long long cur_sum = 0;
        int res = 0;
        for(int i=0; i<nums.size()-1; ++i) {
            cur_sum += (long long)(nums[i]);
            if(cur_sum >= sum - cur_sum) ++res;
        }
        return res;
    }
};
