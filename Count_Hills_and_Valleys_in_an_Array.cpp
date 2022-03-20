// Leetcode 2210

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res = 0;
        for(int i=1; i<nums.size()-1; ++i) {
            if(nums[i] == nums[i-1]) continue;
            int cur = nums[i];
            int j = i-1;
            while(j >= 0 && nums[j] == cur) --j;
            if(j < 0) continue;
            int left_j = j;
            j = i+1;
            while(j < nums.size() && nums[j] == cur) ++j;
            if(j >= nums.size()) continue;
            //cout<<i<<":"<<left_j<<":"<<j<<endl;
            //cout<<"res\t"<<nums[left_j]<<"\t"<<cur<<"\t"<<nums[j]<<endl;
            if(nums[left_j] < cur && nums[j] < cur) ++res;  //hill
            else if(nums[left_j] > cur && nums[j] > cur) ++res;  //valley
            //cout<<"res2\t"<<res<<endl;
        }
        return res;
    }
};
