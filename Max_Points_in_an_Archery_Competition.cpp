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
