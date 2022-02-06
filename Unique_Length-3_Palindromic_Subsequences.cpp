// Leetcode 1930

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.length();
        vector<vector<int>> c2n(n+1, vector<int>(26, 0));  //c2n[i+1]表示从s[0...i]前缀子串中各字符出现的次数
        vector<vector<int>> c2pos(26, vector<int>());   //c2pos['a']记录a在s字符串中出现的位置
        vector<int> cur(26, 0);
        for(int i=0; i<n; ++i) {
            int idx = int(s[i]-'a');
            c2pos[idx].push_back(i);
            cur[idx]++;
            c2n[i+1] = cur;
        }
        int res = 0;
        for(int i=0; i<26; ++i) {
            vector<int> & pos = c2pos[i];
            if(pos.size() <= 1) continue;  //整个字符串只出现了一次该字符，那么形成不了3length的回文（作为第1个字符和第3个字符）
            int start = pos[0], end = pos.back();  //将第1次出现和最后1次出现的位置找到
            //然后，找[start+1, end-1]，中间出现各个字符，如果出现则是一个3length的回文
            vector<int> & cend = c2n[end];
            vector<int> & cstart = c2n[start+1];
            for(int j=0; j<26; ++j) {
                int c = cend[j] - cstart[j];
                if(c > 0) ++res;
            }
        }
        return res;
    }
};
