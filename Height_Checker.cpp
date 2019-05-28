//Leetcode 1051

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> old = heights;
        sort(heights.begin(), heights.end());
        int res=0;
        for(int i=0;i<heights.size();++i) {
            if(heights[i] != old[i]) ++res;
        }
        return res;
    }
};
