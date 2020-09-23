//Leetcode 1578

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int res = 0;
        int cur_cost = INT_MAX;
        char c = ' ';
        for(int i=0;i<s.length();++i) {
          if(s[i] == c) {
            res += min(cur_cost, cost[i]);
            cur_cost = max(cur_cost, cost[i]);
            }
          else {
            c = s[i];
            cur_cost = cost[i];
          }
        }
        return res;
    }
};
