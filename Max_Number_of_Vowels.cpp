//Leetcode 1456

class Solution {
public:
    int maxVowels(string s, int k) {
        int res = 0, cur = 0;
        for(int i=0;i<k&&i<s.length();++i) {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') ++cur;
        }
        res = max(res, cur);
        for(int i=k;i<s.length();++i) {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') ++cur;
            if(s[i-k]=='a' || s[i-k]=='e' || s[i-k]=='i' || s[i-k]=='o' || s[i-k]=='u') --cur;
            res = max(res, cur);
        }
        return res;
    }
};
