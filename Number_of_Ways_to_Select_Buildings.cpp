// Leetcode 2222

class Solution {
public:
    long long numberOfWays(string s) {
        int n=s.length();
        vector<int> pref_0(n+1, 0), pref_1(n+1, 0);  //s中前缀0和1的个数
        for(int i=0; i<n; ++i) {
            if(s[i] == '0') {
                pref_0[i+1] = pref_0[i] + 1;
                pref_1[i+1] = pref_1[i];
            }
            else {
                pref_0[i+1] = pref_0[i];
                pref_1[i+1] = pref_1[i] + 1;
            }
        }
        long long cur_0 = 0, cur_1 = 0;
        long long res = 0;
        for(int i=n-1; i>=0; --i) {
            if(s[i] == '1') {  //以s[i]为第2个buildings，那么前缀和后缀
                res += (cur_0 * pref_0[i]);
                cur_1 += 1;
            }
            else {
                res += (cur_1 * pref_1[i]);
                cur_0 += 1;
            }
        }
        return res;
    }
};
