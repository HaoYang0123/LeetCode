//Leetcode 698
//一个数组，将数组分成k个子数组，每个子数组求和的值相等
//该问题是NP-Hard，但由于问题规模非常小（数组的个数不超过16）。
//下面算法相当于枚举，枚举当前元素落在k个子数组中的哪个，时间复杂度为K^N。有个DP算法，但本人不会，时间复杂度是2^N。

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();++i) sum+=nums[i];
        if (sum%k!=0) return false;
        int target=sum/k;
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        if(nums[n]>target) return false;
        while(n>=0&&nums[n]==target) {
            --n;
            --k;
        }
        vector<int> groups(k,0);
        return dfs(nums, groups, target, n);
    }
    
    bool dfs(vector<int>& nums, vector<int> & groups, int target, int n) {
        if (n<0) return true;
        int v=nums[n--];
        for(int i=0;i<groups.size();++i) {
            if(groups[i]+v<=target) {
                groups[i]+=v;
                if(dfs(nums, groups, target, n)) return true;
                groups[i]-=v;
            }
        }
        return false;
    }
};
