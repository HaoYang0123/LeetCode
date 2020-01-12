//Leetcode 1313

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i+=2) {
            int num = nums[i];
            int val = nums[i+1];
            vector<int> tmp(num, val);
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
        return res;
    }
};
