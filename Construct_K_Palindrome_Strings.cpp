//Leetcode 1400

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() < k) return false;
        int oddnum = 0;
        vector<int> char2num(26, 0);
        for(int i=0;i<s.length();++i) char2num[int(s[i]-'a')]++;
        for(int i=0;i<26;++i) {
            if(char2num[i] % 2 != 0) ++oddnum;
        }
        //cout<<oddnum<<endl;
        return oddnum <= k;
    }
};
