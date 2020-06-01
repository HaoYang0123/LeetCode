//Leetcode 1460

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> v2c;
        for(int t : target) v2c[t]++;
        for(int a : arr) {
            if(v2c[a] == 0) return false;
            v2c[a]--;
        }
        return true;
    }
};
