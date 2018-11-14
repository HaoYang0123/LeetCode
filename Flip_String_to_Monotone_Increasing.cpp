//Leetcode 926
//O(n)复杂度

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n=S.length();
        vector<int> dp,one;
        int zero_count=0; //0的个数
        for(int i=0;i<S.length();++i) {
            if(S[i] == '0') ++zero_count;
        }
        if(zero_count == S.length()) return 0;
        for(int i=0;i<S.length();++i) {
            if(S[i]=='0') --zero_count;
            else {
              dp.push_back(0);
              one.push_back(zero_count);
            }
        }
        dp[dp.size()-1] = min(1, one[one.size()-1]);
        for(int i=dp.size()-2;i>=0;--i) {
            dp[i] = min(1+dp[i+1], one[i]);
        }
        return dp[0];
     }
};
