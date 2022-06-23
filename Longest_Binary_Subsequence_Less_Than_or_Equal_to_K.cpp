// Leetcode 2311

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int res = 0;
        for(int i=0; i<s.length(); ++i) {
            if(s[i] == '0') ++res;
        }
        long long cur = 0;
        for(int i=s.length()-1; i>=0; --i) {
            if(s[i] == '1') {
                int pos = s.length()-1-i;
                if(pos>32) break;
                cur += ((long long)(1)<<pos);
                //cout<<cur<<"\t"<<i<<endl;
                if(cur <= k) ++res;
                else break;
            }
        }
        return res;
    }
};
