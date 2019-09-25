//Leetcode 1200

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n=arr.size();
        int min_dis = INT_MAX;
        for(int i=0;i<n-1;++i) {
            int dis = arr[i+1]-arr[i];
            min_dis = min(min_dis, dis);
        }
        vector<vector<int>> res;
        for(int i=0;i<n-1;++i) {
            int dis = arr[i+1]-arr[i];
            if(dis == min_dis) {
                vector<int> tmp(2, 0);
                tmp[0] = arr[i];
                tmp[1] = arr[i+1];
                res.push_back(tmp);
            }
        }
        return res;
    }
};
