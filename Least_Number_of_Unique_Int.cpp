//Leetcode 1481

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> val2num;
        for(int i=0;i<arr.size();++i) val2num[arr[i]]++;
        vector<pair<int,int>> num_val;
        for(auto ind=val2num.begin(); ind!=val2num.end(); ++ind) {
            num_val.push_back({ind->second, ind->first});
        }
        sort(num_val.begin(), num_val.end()); //pair<int,int>是按照第一个int(即first)从小到大排序
        int i=0;
        for(;i<num_val.size();++i) {
            k -= num_val[i].first;
            if(k < 0) break;
        }
        return num_val.size()-i;
    }
};
