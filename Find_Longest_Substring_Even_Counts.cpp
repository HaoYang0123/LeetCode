//Leetcode 1371

class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> c(26, 0);
        c[int('a'-'a')] = 1;
        c[int('e'-'a')] = 2;
        c[int('i'-'a')] = 4;
        c[int('o'-'a')] = 8;
        c[int('u'-'a')] = 16;
        
        vector<int> m(32, -1); //位索引
        //如果字符串出现a,e,i,o,u，则更新位向量
        //m记录位向量最早出现的位置
        //最后结果就是相同位向量的起始索引至终止索引
        //图解释：https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/discuss/534135/C%2B%2B-with-picture
        int cur_mask = 0, res = 0;
        for(int i=0;i<s.length();++i) {
            cur_mask = cur_mask ^ c[int(s[i]-'a')];
            if(cur_mask != 0 && m[cur_mask] == -1) m[cur_mask] = i;
            res = max(res, i - m[cur_mask]);
        }
        return res;
    }
};
