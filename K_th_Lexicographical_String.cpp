//Leetcode 1415
//数学方法：根据n（字符串长度），可以知道happyString的数量为3*pow(2,n-1)
//num=pow(2,n-1)，如果k<=num，则结果的第1个字符为'a'，否则k<=2*num，则为'b'，否则为'c'
//然后更新k，并且将num更新为num/2，继续判断

class Solution {
public:
    string getHappyString(int n, int k) {
        int num = pow(2, n-1);
        string res = string(1, 'a' + (k-1) / num); //k<=num，则为a，k<=2*num，则为b，否则为c
        while (num > 1) {
            k -= num * ((k - 1) / num);
            num = num / 2;
            res += (k - 1) / num == 0 ? 'a' + (res.back() == 'a') : 'b' + (res.back() != 'c');
        }
        return res;
    }
};
