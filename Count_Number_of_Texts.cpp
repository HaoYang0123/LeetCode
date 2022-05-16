// Leetcode 2266

class Solution {
public:
    int countTexts(string pressedKeys) {
        int mod = 1000000007;
        vector<long long> dp(100003, 0);
        vector<long long> dp2(100003, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp2[0] = 1;
        dp2[1] = 1;
        dp2[2] = 2;
        dp2[3] = 4;
        for(int i=3; i<=pressedKeys.length(); ++i) {
            dp[i] = (dp[i-3] + dp[i-2] + dp[i-1]) % mod;
        }
        for(int i=4; i<=pressedKeys.length(); ++i) {
            dp2[i] = (dp2[i-4] + dp2[i-3] + dp2[i-2] + dp2[i-1]) % mod;
        }
        long long res = 1;
        int cur = 1;
        char c = pressedKeys[0];
        pressedKeys += '#';
        for(int i=1; i<pressedKeys.length(); ++i) {
            if(pressedKeys[i] == c) ++cur;
            else {
                if(c == '7' || c == '9') 
                    res = (res * dp2[cur]) % mod;
                else 
                    res = (res * dp[cur]) % mod;
                c = pressedKeys[i];
                cur = 1;
            }
        }
        return res;
    }
};
