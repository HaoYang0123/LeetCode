//Leetcode 1546

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> ss; //记录当前的求和
        ss.insert(0);
        int res = 0, cur = 0;
        for(int i=0;i<nums.size();++i) {
            cur += nums[i];
            if(ss.find(cur-target) != ss.end()) { //如果当前求和-target存在于之前求和中，那么则存在一个连续子数组求和=target
                ++res;
                cur = 0;
                ss.clear(); //清空ss，相当于从当前位置重新计算求和
                ss.insert(0);
            }
            else ss.insert(cur);
        }
        return res;
    }
};
