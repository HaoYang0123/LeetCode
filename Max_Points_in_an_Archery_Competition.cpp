// Leetcode 2212

class Solution {
public:
     void dfs(int pos, int numArrows, int curScore, vector<int>& sol, int& maxScore, vector<int> cur, vector<int>& aliceArrows) {
        int n = sol.size();
        if (pos == n) {
            if (curScore > maxScore) {
                sol = cur;
                maxScore = curScore;
            }
            return;
        }
        if (pos == n - 1) {
            cur[pos] = numArrows;
            if (numArrows > aliceArrows[pos]) {
                dfs(pos + 1, 0, curScore + pos, sol, maxScore, cur, aliceArrows);
            }
            else {
                dfs(pos + 1, 0, curScore, sol, maxScore, cur, aliceArrows);
            }
            return;
        }
        if (numArrows > aliceArrows[pos]) {
            cur[pos] = aliceArrows[pos] + 1;
            dfs(pos + 1, numArrows - aliceArrows[pos] - 1, curScore + pos, sol, maxScore, cur, aliceArrows);
            cur[pos] = 0;
        }
        dfs(pos + 1, numArrows, curScore, sol, maxScore, cur, aliceArrows);
        
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int n = aliceArrows.size();
        vector<int> sol(n);
        int maxScore = 0;
        dfs(0, numArrows, 0, sol, maxScore, sol, aliceArrows);
        return sol;
    }
};


// 我写的这个代码为何超时了呢？

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<vector<int>> dp(12, vector<int>(numArrows+1, 0));
        vector<vector<bool>> dp_win(12, vector<bool>(numArrows+1, false)); //dp_win[i]表示第i个，是否要击败Alice
        //dp[i][j]表示还有j个箭，对于第i个（是击败Alice还是被击败）的最大得分
        //dp[i][j] = max(dp[i+1][j+a[i]+1]+i, dp[i+1][j])
        //dp[11][0...a[11]]=0
        //dp[11][a[11]+1...]=11
        
        //for(int i=0; i<=aliceArrows[11]; ++i) dp[11][i]=0;
        for(int i=aliceArrows[11]+1; i<=numArrows; ++i) {
            dp[11][numArrows-i]=11;
            dp_win[11][numArrows-i]=true;
        }
        for(int i=10; i>=0; --i) {
            int cur = aliceArrows[i];
            for(int j=0; j<=numArrows; ++j) {
                int add = j+cur+1;
                if(add > numArrows) dp[i][j] = dp[i+1][j];
                else {
                    if(dp[i+1][add]+i > dp[i+1][j]) 
                        dp_win[i][j] = true;
                    dp[i][j] = max(dp[i+1][add]+i, dp[i+1][j]);
                }
            }
        }
        //cout<<dp[0][0]<<endl;
        vector<int> res(12, 0);
        int cur_value = 0, has_value = 0;
        for(int i=0; i<12; ++i) {
            if(dp_win[i][cur_value]) {
                res[i] = aliceArrows[i]+1;
                cur_value += (aliceArrows[i]+1);
            }
            if(i>0) has_value += res[i];
        }
        res[0] = numArrows - has_value;
        return res;
    }
};
