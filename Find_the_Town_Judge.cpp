//Leetcode 997

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<set<int>> dp(N+1);
        for(int i=0;i<trust.size();++i) {
          int a=trust[i][0], b=trust[i][1];
          dp[a].insert(b);
        }
        int town = 0;
        for(int i=1;i<=N;++i) {
          if(dp[i].size()==0) {
            if(town != 0) return -1; //有多个结果
            town = i;
          }
        }
        if(town == 0) return -1;
        for(int i=1;i<=N;++i) {
          if(town == i) continue;
          set<int> v = dp[i];
          if(v.find(town) == v.end()) return -1;
        }
        return town;
    }
};
