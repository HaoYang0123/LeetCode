// Leetcode 2079

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int c = capacity;
        int res = 0;
        for(int i=0; i<plants.size(); ++i) {
            if(c >= plants[i]) {
                ++res;
                c -= plants[i];
            }
            else {
                res += i*2+1;
                c = capacity - plants[i];
            }
        }
        return res;
    }
};
