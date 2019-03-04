//Leetcode 1002

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int n = A.size();
        vector<int> dp(26, INT_MAX); //dp[i]记录('a'+i)出现的最小次数
        for(int i=0;i<n;++i) {
            string c = A[i];
            vector<int> tmp(26, 0);
            for(int j=0;j<c.length();++j) {
                tmp[c[j]-'a']++;
            }
            for(int j=0;j<26;++j) {
                dp[j] = min(dp[j], tmp[j]);
            }
        }
        vector<string> res;
        for(int i=0;i<26;++i) {
            int c = dp[i];
            string v = string(1, 'a'+i);
            for(int j=0;j<c;++j) res.push_back(v);
        }
        return res;
    }
};
