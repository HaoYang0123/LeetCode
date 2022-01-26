// Leetcode 2145
//计算累积的最小值和最大值
//给定数组dif后，那么原数组为：[x, x+dif[0], x+dif[0]+dif[1], x+dif[0]+dif[1]+dif[2], ...]
//那么可以统计一下[0, dif[0], dif[0]+dif[1], dif[0]+dif[1]+dif[2], ...]中的最小值和最大值
//比如最小值是-2，最大值是2，那么它的范围就是4
//给定的lower和upper，范围是upper-lower+1，最终的数据就是upper-lower+1-(max_d-min_d)

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long min_d = 0, max_d = 0;
        long long cur = differences[0];
        min_d = min(min_d, cur);
        max_d = max(max_d, cur);
        for(int i=1; i<differences.size(); ++i) {
            cur += differences[i];
            min_d = min(min_d, cur);
            max_d = max(max_d, cur);
        }
        long long dif = max_d - min_d;
        long long dif2 = upper - lower;
        //cout<<max_d<<"\t"<<min_d<<"\t"<<dif<<"\t"<<dif2<<endl;
        return max(dif2-dif+1ll, 0ll);
    }
};
