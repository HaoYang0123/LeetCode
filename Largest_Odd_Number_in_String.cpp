// Leetcode 1903

class Solution {
public:
    string largestOddNumber(string num) {
        int ind = num.length() - 1;
        while(ind >= 0 && int(num[ind] - '0') % 2 == 0) --ind;
        if(ind < 0) return "";
        return num.substr(0, ind+1);
    }
};
