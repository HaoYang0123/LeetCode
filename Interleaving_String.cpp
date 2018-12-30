//Leetcode 97
//动态规划：dp[i][j]=(dp[i-1][j] if s1[i]==s3[i+j]; dp[i][j-1] if s2[j]==s3[i+j])

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length(), m=s2.length(), p=s3.length();
        if(n+m != p) return false;
        vector<vector<int>> dp(n+2, vector<int>(m+2,0));
        dp[0][0] = 1;
        for(int i=0;i<n;++i) {
            if(s3[i]==s1[i])
                dp[i+1][0] = dp[i][0];
            else dp[i+1][0] = 2;
        }
        for(int i=0;i<m;++i) {
            if(s3[i]==s2[i])
                dp[0][i+1] = dp[0][i];
            else dp[0][i+1] = 2;
        }
        //cout<<"OK"<<endl;
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                bool up = false;
                bool left = false;
                if(s1[i]==s3[i+j+1]) up = (dp[i][j+1] == 1 ? true : false);
                if(s2[j]==s3[i+j+1]) left = (dp[i+1][j] == 1 ? true : false);
                bool cur = (up || left);
                dp[i+1][j+1] = (cur ? 1 : 2);
            }
        }
        return (dp[n][m] == 1 ? true : false);
    }
};
