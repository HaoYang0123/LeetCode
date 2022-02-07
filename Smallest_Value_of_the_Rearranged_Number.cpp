// Leetcode 2165

class Solution {
public:
    long long smallestNumber(long long num) {
        if(num > 0) {
            string ss = to_string(num);
            string nozero = "", zero = "";
            sort(ss.begin(), ss.end());  //从小到大排序
            for(int i=0; i<ss.length(); ++i) {
                if(ss[i] == '0') zero += '0';
                else nozero += ss[i];
            }
            string final_ss = nozero[0] + zero + nozero.substr(1);
            return atoll(final_ss.c_str());
        }
        else if(num < 0) {
            num = -num;
            string ss = to_string(num);
            string nozero = "", zero = "";
            sort(ss.rbegin(), ss.rend());  //从小到大排序
            for(int i=0; i<ss.length(); ++i) {
                if(ss[i] == '0') zero += '0';
                else nozero += ss[i];
            }
            string final_ss = nozero + zero;
            return -atoll(final_ss.c_str());
        }
        return 0;
    }
};
