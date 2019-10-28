//Leetcode 1238
//这道题需要发现规律：
//比如：n=1，那么结果就是0
//比如：n=2，那么结果就是[0,1]，二进制为[0, 1]
//比如：n=3，那么结果就是[0,1,3,2]，二进制为[00,01,11,10]
//比如：n=4，那么结果就是[0,1,3,2,6,7,5,4]，二进制为[000,001,011,010,110,111,101,100]
//我们可以发现一个规律，即n的结果的前半部分一定是n-1结果，后半部分则是将最高位为1对应的结果。
//比如n=3的结果是[00,01,11,10]，那么n=4的结果的前四个数一定一样，而后四个数一定是最高位为1对应的结果[110，111，101，100]（数组顺序换了）

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> res;
        res.push_back(0);
        int floor = 1;
        for(int j=1;j<=n;++j) {
            vector<int> next_floor(res.size(), 0);
            for(int k=0;k<res.size();++k) { //备份后半部分结果
                next_floor[k] = res[res.size()-1-k] + floor; //最高位补1，相当于加上floor值
            }
            res.insert(res.end(), next_floor.begin(), next_floor.end());
            floor *= 2;
        }
        vector<int> res2(res.size(), 0); //结果需要是start开始的，因为是循环约束条件所以直接找到start然后循环走一圈即可
        int startInd = -1;
        for(int i=0;i<res.size();++i) {
            if(res[i] == start) {
                startInd = i;
                break;
            }
        }
        for(int i=startInd; i<startInd+res.size();++i) {
            res2[i-startInd] = res[i%res.size()];
        }
        return res2;
    }
};
