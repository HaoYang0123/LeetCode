//Leetcode 1461

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> ss;
        if(s.length() <= k) return false;
        for(int i=0;i<=s.length()-k;++i) ss.insert(s.substr(i,k));
        return ss.size() == pow(2,k); //只有当ss存了2^k个字符串，说明全部包含了，返回true
    }
};
