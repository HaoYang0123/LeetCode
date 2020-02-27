//Leetcode 1346

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> val2index;
        int zero_num = 0;
        for(int i=0;i<arr.size();++i) {
            if(arr[i] == 0) ++zero_num;
            else {
                val2index[arr[i]] = i;
            }
        }
        if(zero_num > 1) return true;
        for(int i=0;i<arr.size();++i) {
            int val = arr[i]*2;
            auto ind = val2index.find(val);
            if(ind == val2index.end()) continue;
            if(ind->second != i) return true;
        }
        return false;
    }
};
