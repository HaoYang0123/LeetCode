//Leetcode 1374

class Solution {
public:
    string generateTheString(int n) {
        if(n % 2 != 0) {
            string res = "";
            for(int i=0;i<n;++i) res += "a";
            return res;
        }
        string res = "";
        for(int i=0;i<n-1;++i) res += "a";
        res += "b";
        return res;
    }
};
