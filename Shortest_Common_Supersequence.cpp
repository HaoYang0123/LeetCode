//Leetcode 1092
//O(N*M)的时间复杂度

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length(), m=str2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        vector<vector<int>> dp2(n+1, vector<int>(m+1,0)); //1表示从左到右（+str2），2表示从上到下（+str1），3表示对角线
        for(int i=0;i<n;++i) {
            dp2[i+1][0] = 2;
        }
        for(int i=0;i<m;++i) {
            dp2[0][i+1] = 1;
        }
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(str1[i]!=str2[j]) {
                    dp[i+1][j+1]=max(dp[i+1][j], dp[i][j+1]);
                    if(dp[i+1][j]>dp[i][j+1]) dp2[i+1][j+1] = 1;
                    else dp2[i+1][j+1] = 2;
                }
                else {
                    dp[i+1][j+1]=max(dp[i+1][j], max(dp[i][j+1], dp[i][j]+1));
                    if(dp[i+1][j+1] == dp[i][j]+1) {
                        dp2[i+1][j+1] = 3; //or + str2[j] because str1[i]==str2[j]
                    }
                    else if(dp[i+1][j+1] == dp[i+1][j]) {
                        dp2[i+1][j+1] = 1;
                    }
                    else {
                        dp2[i+1][j+1] = 2;
                    }
                }
            }
        }
        //dp2[0][0]=2;
        string res = "";
        int i=n,j=m;
        while((i>0&&j>=0) || (i>=0&&j>0)) {
            if(dp2[i][j] == 3) {
                res += str1[i-1]; //or str2[j-1]
                --i;
                --j;
            }
            else if(dp2[i][j] == 2) {
                res += str1[i-1];
                --i;
            }
            else {
                res += str2[j-1];
                --j;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
