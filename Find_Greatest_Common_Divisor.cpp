// Leetcode 1979

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min_v = INT_MAX, max_v = INT_MIN;
        for(auto v : nums) {
            min_v = min(min_v, v);
            max_v = max(max_v, v);
        }
        for(int i=min_v; i>=1; --i) {
            if(min_v % i == 0 && max_v % i == 0) return i;
        }
        return 0;
    }
};
