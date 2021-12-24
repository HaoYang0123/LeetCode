// Leetcode 2100

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> left2right(n, 0);
        vector<int> right2left(n, 0);
        for(int i=1; i<n; ++i) {
            if(security[i] <= security[i-1]) left2right[i] = left2right[i-1]+1;
        }
        for(int i=n-2; i>=0; --i) {
            if(security[i] <= security[i+1]) right2left[i] = right2left[i+1]+1;
        }
        vector<int> res;
        for(int i=0; i<n; ++i) {
            if(left2right[i] >= time && right2left[i] >= time) res.push_back(i);
        }
        return res;
    }
};
