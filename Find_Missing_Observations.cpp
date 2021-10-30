// Leetcode 2028

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (m+n);
        int cur_sum = 0;
        for(int i=0; i<m; ++i) cur_sum += rolls[i];
        int c = sum - cur_sum;  // 还剩几个
        if(c < n || c > 6*n) return vector<int>();
        vector<int> res(n, 0);
        int me = int(c / n);
        int mod = c % n;
        for(int i=0; i<n; ++i) {
            if(i <  mod) res[i] = me+1;
            else res[i] = me;
        }
        return res;
    }
};
