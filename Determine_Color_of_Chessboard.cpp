// Leetcode 1812

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int row = (int)(coordinates[0] - 'a') + 1;
        int col = (int)(coordinates[1] - '0');
        if(row % 2 != 0) {
            if(col % 2 != 0) return false;
            return true;
        }
        else {
            if(col % 2 != 0) return true;
            return false;
        }
    }
};
