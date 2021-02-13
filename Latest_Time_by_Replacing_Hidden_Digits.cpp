// Leetcode 1736

class Solution {
public:
    string maximumTime(string time) {
        string res = "";
        for(int i=0;i<time.length();++i) {
            if(time[i] == '?') {
                if(i == 0) {
                    if(time[1] == '?' || time[1] <= '3')
                        res += '2';
                    else
                        res += '1';
                }
                else if(i==1) {
                    if(time[0] == '0' or time[0] == '1')
                        res += '9';
                    else
                        res += '3';
                }
                else if(i==3) res += '5';
                else res += '9';
            }
            else res += time[i];
        }
        return res;
    }
};
