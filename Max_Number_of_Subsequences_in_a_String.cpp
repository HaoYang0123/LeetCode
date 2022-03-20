// Leetcode 2207

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long res = 0;
        if(pattern[0] == pattern[1]) {
            //如果是相同元素
            int num = 0;
            for(int i=0; i<text.length(); ++i) {
                if(text[i] == pattern[0]) ++num;
            }
            ++num;  //将pattern加进去
            res = ((long long)num * (num-1)) / 2;
        }
        else {
            //如果是不同元素
            long long num1 = 0, num2 = 0;
            long long res1 = 0, res2 = 0;  // res1表示插入pattern[0]的最大数，res2表示插入pattern[1]的最大数
            //插入一定插入在最前面
            ++num1;  //先把pattern[0]插入最前面
            for(int i=0; i<text.length(); ++i) {
                if(text[i]==pattern[0]) ++num1;
                else if(text[i]==pattern[1]) res1 += num1;
            }
            ++num2;  //第二轮，把pattern[1]插入最后面
            for(int i=text.length()-1; i>=0; --i) {
                if(text[i]==pattern[1]) ++num2;
                else if(text[i]==pattern[0]) res2 += num2;
            }
            res = max(res1, res2);
        }
        return res;
    }
};
