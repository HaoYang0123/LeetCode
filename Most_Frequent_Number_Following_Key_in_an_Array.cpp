// Leetcode 2190

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> target2num;
        for(int i=1; i<nums.size(); ++i) {
            if(nums[i-1] != key) continue;
            target2num[nums[i]]++;
        }
        int res = -1, max_num = 0;
        for(auto idx=target2num.begin(); idx!=target2num.end(); ++idx) {
            if(max_num < idx->second) {
                max_num = idx->second;
                res = idx->first;
            }
        }
        return res;
    }
};
