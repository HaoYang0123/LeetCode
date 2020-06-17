//Leetcode 1477

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int MAX_V = 1000000;
        vector<int> dp(n, MAX_V); //dp[i]表示从arr[0,...i]的最短长度（sum=target）
        int sum = 0, start = 0; //sum表示记录当前窗口[start至i]的求和
        int res = MAX_V;
        for(int i=0;i<n;++i) {
            if(i>0) dp[i] = dp[i-1]; //dp是递减的，dp[i]<=dp[i-1]
            sum += arr[i];
            while(sum>target) sum -= arr[start++]; //如果当前[start至i]求和大于target【注：arr均是正数】，所以需要将start++
            if(sum == target)  { //当[start至i]的求和等于target，说明找到了sub-array
                dp[i] = min(dp[i], i-start+1); //更新dp[i]，[start至i]的长度等于i-start+1
                if(start > 0) { //如果start是大于0，那么可能dp[start-1]记录了[0,start-1]的最短sub-array
                    //cout<<"\t"<<start<<"\t"<<i<<"\t"<<dp[start-1] + (i-start+1)<<endl;
                    res = min(res, dp[start-1] + (i-start+1)); //将两个sub-array长度加起来，更新res结果
                }
            }
        }
        //for(int i=0;i<n;++i) cout<<i<<"\t"<<dp[i]<<endl;
        if(res >= MAX_V) return -1; //如果res还是等于MAX_V，说明没找到两个sub-array
        return res;
    }
};
