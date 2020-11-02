//Leetcode 1636

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> val2num;
        for(int i=0;i<nums.size();++i) {
            val2num[nums[i]]++;
        }
        map<int,vector<int>> num2val;
        for(auto ind=val2num.begin(); ind!= val2num.end(); ++ind) {
            num2val[ind->second].push_back(ind->first);
        }
        vector<int> res;
        for(auto ind=num2val.begin(); ind!= num2val.end(); ++ind) {
            vector<int> & cur_nums = ind->second;
            sort(cur_nums.begin(), cur_nums.end());
            int num = ind->first;
            for(int i=cur_nums.size()-1;i>=0;--i) {
                for(int j=0;j<num;++j) {
                    res.push_back(cur_nums[i]);
                }
            }
        }
        return res;
    }
};
