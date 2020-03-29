//Leetcode 1390

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        unordered_map<int,int> val2sum; //val2sum[v]表示v的divisors（num=4）的和
        int res = 0;
        for(int i=0;i<nums.size();++i) {
            auto ind = val2sum.find(nums[i]);
            int t = 0;
            if(ind != val2sum.end()) t = ind->second;
            else {
                t = get_div(nums[i]);
                val2sum[nums[i]] = t;
            }
            //cout<<"HH\t"<<nums[i]<<"\t"<<t<<endl;
            res += t;
        }
        return res;
    }
    inline int get_div(int v) {
        int div_num = 2;
        int res = 1 + v;
        int end = sqrt(v);
        if(end * end == v) return 0;
        //cout<<v<<":";
        for(int i=2;i<end+1;++i) {
            if(v % i == 0) {
                //cout<<"\t"<<i<<"|"<<v/i;
                div_num += 2;
                if(div_num > 4) return 0;
                res += (i + v/i);
            }
        }
        //cout<<endl;
        if(div_num == 4) return res;
        return 0;
    }
};
