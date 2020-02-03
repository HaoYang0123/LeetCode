//Leetcode 1331

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> res(arr.size(), 0);
        map<int, int> val2count;
        for(int i=0;i<arr.size();++i) val2count[arr[i]]++;
        map<int, int> val2rank;
        int rank = 1;
        for(auto ind = val2count.begin(); ind != val2count.end();++ind){
            val2rank[ind->first] = rank;
            //rank += ind->second;
            rank++;
        }
        for(int i=0;i<arr.size();++i) {
            res[i] = val2rank[arr[i]];
        }
        return res;
    }
};
