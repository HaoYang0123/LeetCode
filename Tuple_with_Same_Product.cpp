// Leetcode 1726

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> v2c; //记录nums[i]*nums[j]的数量
        for(int i=0;i<nums.size();++i) {
            for(int j=i+1;j<nums.size();++j) {
                v2c[nums[i]*nums[j]]++;
            }
        }
        long long res = 0;
        for(auto ind = v2c.begin(); ind != v2c.end(); ++ind) {
            if(ind->second < 2) continue;
            long long v = (long long)(ind->second);
            res += (v * (v-1)) / 2;  //相当于C(N, 2)，比如[2,3,4,6]，那么v2c[12]=2，说明有两组结果相乘等于12，所以可以从两组中选择两个组出来给a,b,c,d
        }
        return res * 8; //最后将a,b,c,d进行置换，比如：(a,b,c,d), (a,b,d,c), (b,a,c,d), (b,a,d,c), (c,d,a,b),...,总共8种情况
    }
};
