// Leetcode 2224

class Solution {
public:
    int convertTime(string current, string correct) {
        int cur = get_min(current);
        int cor = get_min(correct);
        int delta = cor - cur;
        int res = 0;
        while(delta >= 60) {
            int num = delta / 60;
            delta -= num*60;
            res += num;
        }
        while(delta >= 15) {
            int num = delta / 15;
            delta -= num*15;
            res += num;
        }
        while(delta >= 5) {
            int num = delta / 5;
            delta -= num*5;
            res += num;
        }
        res += delta;
        return res;
    }
    inline int get_min(string one) {
        int hour = 0, minute = 0;
        hour += int(one[0] - '0') * 10;
        hour += int(one[1] - '0');
        minute += int(one[3] - '0') * 10;
        minute += int(one[4] - '0');
        return hour * 60 + minute;
    }
};
