// Leetcode 1758


class Solution {
public:
    int minOperations(string s) {
        //由于最终的字符串要么是"0101..."，要么是"1010..."，所以直接判断哪个转换需要的次数最小
        int res1 = 0, res2 = 0; //res1表示将s改变为"0101..."所用的次数、res2表示将s改变为"1010..."所用的次数
        for(int i = 0; i < s.length(); ++i) {
            if(i % 2 == 0) {
                if(s[i] == '1') ++res1;
                else ++res2;
            }
            else {
                if(s[i] == '0') ++res1;
                else ++res2;
            }
        }
        return min(res1, res2);
    }
};
