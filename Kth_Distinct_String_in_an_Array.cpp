// Leetcode 2053

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> str2num;
        for(int i=0; i<arr.size(); ++i) str2num[arr[i]]++;
        for(int i=0; i<arr.size(); ++i) {
            if(str2num[arr[i]] == 1) {
                --k;
                if(k == 0) return arr[i];
            }
        }
        return "";
    }
};
