//Leetcode 1356

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> data;
        for(int i=0;i<arr.size();++i) {
            data.push_back(pair<int,int>(get_bit(arr[i]), arr[i]));
        }
        sort(data.begin(), data.end());
        vector<int> res;
        for(int i=0;i<data.size();++i) res.push_back(data[i].second);
        return res;
    }
    
    inline int get_bit(int n) {
        int res = 0;
        while(n>0) {
            if(n%2 != 0) ++res;
            n /= 2;
        }
        return res;
    }
};
