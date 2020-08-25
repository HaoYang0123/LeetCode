//Leetcode 1544

class Solution {
public:
    string makeGood(string s) {
        int is_good_idx = is_good(s);
        while(is_good_idx >= 0) {
            s = s.substr(0, is_good_idx) + s.substr(is_good_idx+2, s.length()-is_good_idx-2);
            is_good_idx = is_good(s);
        }
        return s;
    }
    
    inline int is_good(string & s) {
        if(s == "") return -1; //一定要加上这句
        for(int i=0;i<s.length()-1;++i) { //因为，这里i<s.length()-1，如果s.length()=0，返回的是无符号数，s.length()-1返回不是-1，而是一个非常大的正整数
            int a = int(s[i]-'a');
            int A = int(s[i]-'A');
            int a2 = int(s[i+1]-'a');
            int A2 = int(s[i+1]-'A');
            if(a == A2 || A == a2) return i;
        }
        return -1;
    }
};
