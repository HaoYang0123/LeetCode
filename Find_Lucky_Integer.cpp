//Leetcode 1394

class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> val2num;
        for(int i=0;i<arr.size();++i) {
            val2num[arr[i]]++;
        }
        for(auto ind = val2num.rbegin(); ind != val2num.rend(); ++ind) {
            if(ind->first == ind->second) return ind->first;
        }
        return -1;
    }
};
