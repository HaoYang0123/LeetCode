// Leetcode 2167

class Solution {
public:
    int minimumTime(string s) {
        int n=s.length();
        vector<int> right(n+1, 0);  //right[i]表示从s[i...(n-1)]的最小操作步数（从右往左删除1）
        for(int i=n-1; i>=0; --i) {
            if(s[i] == '0') {
                right[i] = right[i+1];
            }
            else {
                right[i] = min(right[i+1]+2, n-i);
            }
        }
        //left表示从左向右删除1的最小步数
        int left = 0, res = right[0];  //res=right[0]表示全部从右边进行去掉
        for(int i=0; i<n; ++i) {
            if(s[i] == '1') {
                left = min(left+2, i+1);
                res = min(res, left+right[i+1]);  //left，当前是s[0-i]从左往右删除的最小步数，right[i+1]则表示对s[(i+1)...(n-1)]从右往左的最小步数，两个求和就是最终的最小步数
            }
        }
        return res;
    }
};
