//Leetcode 949
//全枚举所有的排列，然后去掉小时超过23，分钟超过59的解，在其中找到最大的即可

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(), A.end());
        int max_minute = INT_MIN;
        vector<int> res;
        do {
            int h = A[0]*10+A[1];
            if (h>23) continue;
            int m = A[2]*10+A[3];
            if (m>59) continue;
            int minute = h*60+m;
            if(minute > max_minute) {
                max_minute = minute;
                res = A;
            }
        }while(next_permutation(A.begin(), A.end())); //使用C++自带的全排列工具
        if(max_minute == INT_MIN) return "";
        return get_c(res[0])+get_c(res[1])+":"+get_c(res[2])+get_c(res[3]);
    }
    string get_c(int a) {
        return string(1, char('0'+a));
    }
};
