//Leetcode 1433

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int flag = 0; //如果为1，表示s1<s2；如果为-1，表示s1>s2
        for(int i=0;i<s1.length();++i) {
            if(s1[i] == s2[i]) continue;
            if(s1[i] < s2[i]) {
                if(flag == -1) return false;
                flag = 1;
            }
            else {
                if(flag == 1) return false;
                flag = -1;
            }
        }
        return true;
    }
};
