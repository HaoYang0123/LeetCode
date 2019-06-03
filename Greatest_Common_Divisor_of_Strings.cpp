//Leetcode 1071

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.length() < str2.length()) {
            string str3 = str1;
            str1 = str2;
            str2 = str3;
        }
        for(int i=1; i<=str2.length(); ++i) { //枚举所有的长度情况
            if(str2.length() % i != 0) continue;
            int len = str2.length()/i;
            string tmp = str2.substr(0, len);
            if(is_ok(tmp, str2) && is_ok(tmp, str1)) return tmp;
        }
        return "";
    }
    
    bool is_ok(string tmp, string str) {
        int len1 = tmp.length();
        int len2 = str.length();
        if(len2 % len1 != 0) return false;
        int j=0;
        for(int i=0;i<len2;++i) {
            if(str[i] != tmp[j]) return false;
            ++j;
            if(j>=len1) j=0;
        }
        return true;
    }
};
