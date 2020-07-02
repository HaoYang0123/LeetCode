//Leetcode 1497
//计算余数的数量
//比如：k=5，arr=[1,2,3,4,5,6,7,8,9,10]
//那么remainder2num[0]=2（因为有5和10）、remainder2num[1]=2,....
//则可以枚举remainder2num[i] == remainder2num[k-i] for i in [0,k]，判断是否两者是否相等，如果不相等则说明不能形成pair
//当然得考虑余数为0的情况和负数的情况

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> remainder2num;
        for(int i=0;i<arr.size();++i) {
            int rem = arr[i] % k;
            if(rem < 0) rem += k; //比如：-1%5应该=4，这样才能与余数为1，形成pair，让两个数求和可以被k整除
            remainder2num[rem]++;
        }
        //for(auto ind = remainder2num.begin(); ind != remainder2num.end(); ++ind) cout<<ind->first<<":"<<ind->second<<endl;
        if(remainder2num[0] % 2 != 0) return false;
        for(auto ind = remainder2num.begin(); ind != remainder2num.end(); ++ind) {
            if(ind->first == 0) continue;
            int rem = ind->first;
            int rem2 = k - rem;
            auto ind2 = remainder2num.find(rem2);
            int val = 0;
            if(ind2 != remainder2num.end()) val = ind2->second;
            //cout<<"\t"<<rem<<":"<<ind->second<<"\t"<<rem2<<":"<<val<<endl;
            if(ind->second != val) return false;
        }
        return true;
    }
};
