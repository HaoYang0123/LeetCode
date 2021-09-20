// Leetcode 1996

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end());

        int res = 0, n = properties.size();
        int first_max = properties[n-1][0];
        int second_max_not = 0;
        int second_max = properties[n-1][1];
        for(int i=n-2; i>=0; --i) {
            if(properties[i][0] != first_max) {
                if(second_max > properties[i][1]) ++res;
                second_max_not = max(second_max_not, second_max);
            }
            else {
                if(second_max_not > properties[i][1]) ++res;
            }
            second_max = max(second_max, properties[i][1]);
            first_max = properties[i][0];
        }
        return res;
    }
};
