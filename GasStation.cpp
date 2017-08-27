//有一个循环路径，gas[i]表示第i点可以加的汽油量，cost[i]表示第i到(i+1)费的汽油量。假设汽车本生测量为空，问汽车应该从哪个点开始可以走完一圈。LeetCode134
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) { //O(n)时间复杂度，O(1)空间复杂度
        //可以将gas[i]-cost[i]作为一个新的data[i]，在data数组中找最大的连续子序列求和。如果整个序列求和为负数，那么没有解；如果中间的求和为负数，则重新计算新的起点
        int start = 0, total1 = 0, total2 = 0, tank = 0; //tank记录当前还剩多少汽油
        for(int i = 0; i < gas.size(); ++i) {
            tank += gas[i] - cost[i];
            total1 += gas[i];
            total2 += cost[i];
            if(tank < 0) { //如果tank<0，则表示之前均不能够作为起点，则start等于(i+1)开始重新算
                start = i + 1;
                tank = 0;
            }
        }
        return (total1 < total2 ? -1 : start); //如果总共的汽油量比所费的汽油要少，那么肯定没有任意点能够走完一圈。
    }
};
