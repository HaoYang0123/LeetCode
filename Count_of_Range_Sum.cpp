//Leetcode 327

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        map<long long, int> dp; //dp[i]表示从nums[0:]求和为i的数目，long long防止求和超过int范围
        dp[0] = 1; //处理直接从0开始的数目
        long long sum=0, res=0;
        for(int i=0;i<nums.size();++i) {
            sum += nums[i];
            auto ll = dp.lower_bound(sum-upper); //在dp中找到第一个>=sum-upper的位置
            auto rr = dp.upper_bound(sum-lower); //在dp中找到第一个>sum-lower的位置
            for(auto ind=ll;ind!=rr;++ind) { //在dp中值为[sum-upper, sum-lower]范围内的数目
            //这样sum-X的范围即在[lower, upper]范围内
                res += ind->second;
            }
            dp[sum]++;
        }
        return res;
    }
};
