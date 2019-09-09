//Leetcode 1185

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        if(month==1||month==2) {
            month+=12;
            year--;
        }
        int iWeek = (day + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400) % 7;
        if(iWeek==0) return "Monday";
        else if(iWeek==1) return "Tuesday";
        else if(iWeek==2) return "Wednesday";
        else if(iWeek==3) return "Thursday";
        else if(iWeek==4) return "Friday";
        else if(iWeek==5) return "Saturday";
        return "Sunday";
    }
};
