// Leetcode 2206

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> val2num;
        for(int i=0; i<nums.size(); ++i) val2num[nums[i]]++;
        for(auto idx=val2num.begin(); idx!=val2num.end(); ++idx) {
            if(idx->second % 2 != 0) return false;
        }
        return true;
    }
};
