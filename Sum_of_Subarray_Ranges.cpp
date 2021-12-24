// Leetcode 2104

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0;
        for(int i=0; i<nums.size(); ++i) {
            long long min_v = nums[i], max_v = nums[i];
            for(int j=i; j<nums.size(); ++j) {
                min_v = min(min_v, (long long)nums[j]);
                max_v = max(max_v, (long long)nums[j]);
                res += (max_v - min_v);
            }
        }
        return res;
    }
};
