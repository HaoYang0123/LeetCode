//Leetcode 1124
//O(N)的时间复杂度，sum表示前缀和，当sum为正值时，说明从0至当前位置i，为当前最长的解（长度等于i+1）
//当sum为负值时，得找到一个sum-1的最早出现的位置，那么sum-(sum-1)得到的解为1，符合要求
//这里，为何不找比sum-1小的出现的位置呢，前缀和比sum-1小的得到的区间求和>1，也是符合要求的，但是这种情况的长度并没有上述得到的长度长
//这是因为sum是具有单调性，sum[0]=0,sum[1]只能是1或者-1，sum[2]只能是sum[1]+1或者sum[1]-1，所以sum-1一定出现在比sum-1小的前面

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int sum=0,res=0;
        unordered_map<int, int> val2pos; //val2pos[i]表示前缀和等于i的最早出现的位置
        for(int i=0;i<hours.size();++i) {
            sum += (hours[i] > 8 ? 1 : -1);
            //cout<<sum<<"\t"<<res<<endl;
            if(sum > 0) res = i+1;
            else if(val2pos.find(sum-1) != val2pos.end()) {
                res = max(res, i-val2pos[sum-1]);
            }
            if(val2pos.find(sum) == val2pos.end()) val2pos[sum] = i;
        }
        return res;
    }
};
