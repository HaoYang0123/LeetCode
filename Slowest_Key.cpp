//Leetcode 1629

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char res = ' ';
        int cur_max = INT_MIN;
        for(int i=0;i<releaseTimes.size();++i) {
            int c = 0;
            if(i==0) c = releaseTimes[0];
            else c = releaseTimes[i] - releaseTimes[i-1];
            if(c > cur_max || (c == cur_max && res < keysPressed[i])) {
                res = keysPressed[i];
                cur_max = c;
            } 
        }
        return res;
    }
};
