//Leetcode 1207

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> val2num;
        for(int i=0;i<arr.size();++i) val2num[arr[i]]++;
        unordered_set<int> nums;
        for(auto ind = val2num.begin(); ind != val2num.end(); ++ind) {
            int num = ind->second;
            if(nums.find(num) != nums.end()) return false;
            nums.insert(num);
        }
        return true;
    }
};
