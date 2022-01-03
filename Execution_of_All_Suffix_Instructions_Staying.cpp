// Leetcode 2120

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> res;
        for(int i=0; i<s.length(); ++i) {
            int ci = startPos[0], cj = startPos[1];
            int c = 0;
            for(int j=i; j<s.length(); ++j) {
                if(s[j] == 'R') cj++;
                else if(s[j] == 'L') cj--;
                else if(s[j] == 'U') ci--;
                else ci++;
                if(ci < 0 || ci >= n || cj < 0 || cj >= n) break;
                ++c;
            }
            res.push_back(c);
        }
        return res;
    }
};
