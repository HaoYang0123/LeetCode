// Leetcode 1748

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> val2num;
        for(int i=0;i<nums.size();++i) {
            val2num[nums[i]]++;
        }
        int res = 0;
        for(auto ind=val2num.begin(); ind != val2num.end(); ++ind) {
            if(ind->second > 1) continue;
            res += ind->first;
        }
        return res;
    }
};
