//Leetcode 1375

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int res = 0;
        int max_v = -1;
        for(int i = 0; i < light.size(); ++i) {
            max_v = max(max_v, light[i]);
            if(max_v == i+1) ++res;
        }
        return res;
    }
};
