//Leetcode 1247

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if(s1==s2) return 0;
        string new_s1 = "", new_s2 = "";
        int x_num1 = 0, x_num2 = 0;
        for(int i=0;i<s1.length();++i) {
            if(s1[i]=='x') ++x_num1;
            if(s2[i]=='x') ++x_num1;
            if(s1[i] != s2[i]) {
                new_s1 += s1[i];
                new_s2 += s2[i];
                if(s1[i]=='x') ++x_num2;
            }
        }
        //cout<<new_s1<<'\t'<<new_s2<<endl;
        if(x_num1 % 2 == 1) return -1; //如果x出现的次数是奇数（y次数也是奇数），则不能解决
        if(x_num2 % 2 == 0) return new_s1.length() / 2; //如果new_s1中出现的x次数是偶数，则直接置换
        //比如：s1="xxyy"和s2="yyxx"（注s1和s2的长度一定是偶数，因为x(y)的次数等于s1的长度
        //则直接将s1[0]与s2[1]置换，s1[2]与s2[3]置换
        return new_s1.length() / 2 + 1;
        //如果new_s1中x次数是奇数，则需要多置换一次
        //比如：s1="xxxy"和s2="yyyx"，需要多置换一次（类似xy与yx需要置换两次）
    }
};
