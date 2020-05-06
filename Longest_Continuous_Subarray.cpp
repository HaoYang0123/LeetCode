//Leetcode 1438
//slide window + multiset

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> cnts;
        int j = 0, res = 0; //j是左指针
        for (int i = 0; i < nums.size(); ++i) { //i是右指针
            cnts.insert(nums[i]);
            while (*cnts.rbegin() - *cnts.begin() > limit)
                cnts.erase(cnts.find(nums[j++]));
            res = max(res, i - j + 1);
        }
        return res;
    }
};
