//Leetcode 1539

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> ss;
        for(int i=0;i<arr.size();++i) {
            ss.insert(arr[i]);
        }
        for(int i=1;i<=2000;++i) {
            if(ss.find(i) == ss.end()) {
                --k;
                if(k==0) return i;
            }
        }
        return 0;
    }
};
