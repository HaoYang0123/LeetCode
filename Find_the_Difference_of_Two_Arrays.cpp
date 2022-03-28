// Leetcode 2215

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1 = vec2set(nums1);
        unordered_set<int> set2 = vec2set(nums2);
        vector<int> dif1, dif2;
        for(auto idx=set1.begin(); idx!=set1.end(); ++idx) {
            if(set2.find(*idx) == set2.end()) dif1.push_back(*idx);
        }
        for(auto idx=set2.begin(); idx!=set2.end(); ++idx) {
            if(set1.find(*idx) == set1.end()) dif2.push_back(*idx);
        }
        return {dif1, dif2};
    }
    
    inline unordered_set<int> vec2set(vector<int> & nums) {
        unordered_set<int> res;
        for(int i=0; i<nums.size(); ++i) res.insert(nums[i]);
        return res;
    }
};
