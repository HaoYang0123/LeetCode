// Leetcode 1763

class Solution {
public:
    string longestNiceSubstring(string s) {
        int k = 0;
        string res = "";
        for(int i=0;i<s.length(); ++i) {
            for(int j=i;j<s.length();++j) {
                if(j-i+1 <= k) continue;
                if(is_nice(s, i, j)) {
                    res = s.substr(i, j-i+1);
                    k = j-i+1;
                }
            }
        }
        return res;
    }
    
    inline bool is_nice(string & s, int i, int j) {
        unordered_map<char, int> mm;
        for(int k=i;k<=j;++k) {
            mm[s[k]]++;
        }
        for(auto ind = mm.begin(); ind != mm.end(); ++ind) {
            if(ind->first >= 'a' && ind->first <= 'z') {
                char A = char('A' + int(ind->first - 'a'));
                if(mm.find(A) == mm.end()) return false;
            }
            else {
                char a = char('a' + int(ind->first - 'A'));
                if(mm.find(a) == mm.end()) return false;
            }
        }
        return true;
    }
};
