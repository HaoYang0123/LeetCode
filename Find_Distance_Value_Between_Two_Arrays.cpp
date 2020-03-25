//Leetcode 1385

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        for(int i=0;i<arr1.size();++i) {
            if(!find_valide(arr1[i], arr2, d)) ++res;
        }
        return res;
    }
    
    inline bool find_valide(int v, vector<int> & arr2, int d) {
        for(int i=0;i<arr2.size();++i) {
            if(abs(arr2[i]-v) <= d) return true;
        }
        return false;
    }
};
