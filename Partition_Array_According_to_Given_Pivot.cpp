// Leetcode 2161

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> small, big;
        int equal_num = 0;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i] < pivot) small.push_back(nums[i]);
            else if(nums[i] > pivot) big.push_back(nums[i]);
            else equal_num++;
        }
        for(int i=0; i<equal_num; ++i) small.push_back(pivot);
        small.insert(small.end(), big.begin(), big.end());
        return small;
    }
};
