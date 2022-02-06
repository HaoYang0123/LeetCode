// Leetcode 2164

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd, even;
        for(int i=0; i<nums.size(); ++i) {
            if(i % 2 == 0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        sort(odd.rbegin(), odd.rend());
        sort(even.begin(), even.end());
        vector<int> res(nums.size(), 0);
        for(int i=0; i<nums.size(); ++i) {
            if(i % 2 == 0) res[i] = even[i/2];
            else res[i] = odd[i/2];
        }
        return res;
    }
};
