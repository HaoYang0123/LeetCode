// Leetcode 2200

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> key_idx;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i]==key) key_idx.push_back(i);
        }
        set<int> ss;
        for(int i=0; i<key_idx.size(); ++i) {
            int idx = key_idx[i];
            for(int j=max(0, idx-k); j<=min(int(nums.size())-1, idx+k); ++j) ss.insert(j);
        }
        vector<int> res;
        for(auto idx=ss.begin(); idx!=ss.end(); ++idx) res.push_back(*idx);
        return res;
    }
};
