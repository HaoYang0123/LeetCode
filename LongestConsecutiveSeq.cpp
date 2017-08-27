//计算一个无序数组中的最长的连续子数组的长度：
//比如：
//Given [100, 4, 200, 1, 3, 2],
//The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); ++i) {
            if(map.find(nums[i]) != map.end()) continue; //如果有重复项，必须不考虑，如果考虑会出错
            auto ind1 = map.find(nums[i] - 1), ind2 = map.find(nums[i] + 1);
            int left = (ind1 == map.end() ? 0 : ind1->second);
            int right = (ind2 == map.end() ? 0 : ind2->second);
            int sum = left + right + 1;
            res = max(res, sum);
            map[nums[i]] = sum; //将自己以及左边界和右边界置为sum
            map[nums[i] - left] = sum;
            map[nums[i] + right] = sum;
        }
        return res;
    }
};
