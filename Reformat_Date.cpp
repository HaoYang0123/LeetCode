//Leetcode 1507

class Solution {
public:
    string reformatDate(string date) {
        int day = 0;
        int month = 0;
        int year = 0;
        unordered_map<string, int> m2m;
        m2m["Jan"] = 1;
        m2m["Feb"] = 2;
        m2m["Mar"] = 3;
        m2m["Apr"] = 4;
        m2m["May"] = 5;
        m2m["Jun"] = 6;
        m2m["Jul"] = 7;
        m2m["Aug"] = 8;
        m2m["Sep"] = 9;
        m2m["Oct"] = 10;
        m2m["Nov"] = 11;
        m2m["Dec"] = 12;
        int flag = 0; //0是day, 1是month，2是year
        string mstr = "";
        for(int i=0;i<date.length();++i) {
            if(date[i] == ' ') {
                ++flag;
            }
            else {
                if(flag == 0 && date[i] >= '0' && date[i] <= '9') {
                    day = day*10 + int(date[i]-'0');
                }
                else if(flag == 1) {
                    mstr += date[i];
                }
                else if(flag == 2){
                    year = year*10 + int(date[i]-'0');
                }
            }
        }
        month = m2m[mstr];
        return to_str(year, 4) + "-" + to_str(month, 2) + "-" + to_str(day, 2);
    }
    
    inline string to_str(int v, int dim) {
        int bit = 0;
        int tmp = v;
        while(tmp>0) {
            ++bit;
            tmp /= 10;
        }
        if(bit == dim) return to_string(v);
        string res = "";
        for(int i=0;i<dim-bit;++i) res += "0";
        return res + to_string(v);
    }
};
