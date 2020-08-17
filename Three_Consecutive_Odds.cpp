//Leetcode 1550

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size() < 3) return false;
        for(int i=0;i<arr.size()-2;++i) {
            if(is_odd(arr[i]) && is_odd(arr[i+1]) && is_odd(arr[i+2])) return true;
        }
        return false;
    }
    
    inline bool is_odd(int n) {
        return n%2;
    }
};
