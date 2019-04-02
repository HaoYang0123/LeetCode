//Leetcode 1017
//网上找的答案

class Solution {
public:
    string baseNeg2(int N) {
        if(N == 0) return "0";
        string str;
        int p = 1;
        while(N)
        {
            auto r = N % 2;
            str.push_back('0' + r);
            N = (N - p * r) / 2; //与常规的不同在于，常规的方法：N = (N-r)/2，而这里相当于有两种选择
            p *= -1;
        }
        
        reverse(str.begin(), str.end());
        return str;
    }
};
