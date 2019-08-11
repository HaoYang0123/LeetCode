//Leetcode 1154

class Solution {
public:
    bool is_rui(int year) {
        if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) return true;
        else return false;
    }
    int dayOfYear(string date) {
        int year=0,month=0,day=0;
        string years = date.substr(0, 4);
        string months = date.substr(5, 2);
        string days = date.substr(8, 2);
        year = atoi(years.c_str());
        month = atoi(months.c_str());
        day = atoi(days.c_str());
        if(month <= 2) {
            if(month == 1) return day;
            return 31 + day;
        }
        int ddd[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int res = 0;
        if(is_rui(year)) ++res;
        for(int i=0;i<month-1;++i) {
            res += ddd[i];
        }
        res += day;
        return res;
    }
};
