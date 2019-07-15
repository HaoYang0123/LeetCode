//Leetcode 1122

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> val2num;
        unordered_map<int,bool> is_vis;
        for(int i=0;i<arr1.size();++i) {
            val2num[arr1[i]]++;
        }
        vector<int> res(arr1.size(),0);
        int ri=0;
        for(int i=0;i<arr2.size();++i) {
            is_vis[arr2[i]] = true;
            for(int j=0;j<val2num[arr2[i]];++j) {
                res[ri++]=arr2[i];
            }
        }
        vector<int> not_insert;
        for(int i=0;i<arr1.size();++i) {
            if(is_vis.find(arr1[i]) != is_vis.end()) continue;
            not_insert.push_back(arr1[i]);
        }
        sort(not_insert.begin(), not_insert.end());
        for(int j=0;j<not_insert.size();++j) res[ri++] = not_insert[j];
        return res;
    }
};
