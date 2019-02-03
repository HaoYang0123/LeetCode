//Leetcode 984

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string res = "";
        while (A > 0 || B > 0) {
            bool writeA = false;
            int L = res.length();
            if (L >= 2 && res[L-1] == res[L-2]) {
                if(res[L-1] == 'b') writeA = true;
            }
            else {
                if (A >= B) writeA = true;
            }
            if(writeA) {
                --A;
                res += 'a';
            }
            else {
                --B;
                res += 'b';
            }
        }
        return res;
    }
};
