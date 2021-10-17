// Leetcode 2023

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int res = 0;
        for(int i=0; i<nums.size(); ++i) {
            for(int j=0; j<nums.size(); ++j) {
                if(i == j) continue;
                if(is_equal(nums[i], nums[j], target)) ++res;
            }
        }
        return res;
    }
    
    inline bool is_equal(string & a, string & b, string & t) {
        if(a.length()+b.length() != t.length()) return false;
        return a+b == t;
    }
};
