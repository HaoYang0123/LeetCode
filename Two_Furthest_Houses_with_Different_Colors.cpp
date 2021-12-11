// Leetcode 2078

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        for (int l = colors.size(); l >= 1; --l) {
            for(int i = 0;  i + l - 1 < colors.size(); ++i) {
                if(colors[i] != colors[i+l-1]) return l-1;
            }
        }
        return 0;
    }
};
