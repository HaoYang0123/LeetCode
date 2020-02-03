//Leetcode 1337
//看的题解，不太明白。字符串只有a和b，问从字符串选择一些子串（可以非连续），子串为回文串，删除后，最后删除为空的最少步数

class Solution {
public:
    int removePalindromeSub(string s) {
        if(s=="") return 0;
        if(is_palindrome(s)) return 1; //如果是回文就是一步
        return 2; //为何不是回文，则只用两步呢？举个例子："aabbaba"->(abbba删除)"aa"->""
    }
    
    inline bool is_palindrome(string & s) {
        for(int i=0;i<s.length()/2;++i) {
            if(s[i] != s[s.length() - 1 - i]) return false;
        }
        return true;
    }
};
