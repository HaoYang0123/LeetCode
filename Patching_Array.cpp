//Leetcode 330

class Solution {
public:
    int minPatches(vector<int>& nums, int n) { //nums是从小到大排序的
        //auto dp = vector<bool> (n+1, false);
        // dp[0] = true;
        long long minT = 0; //当前将nums[0:i](加上需要插入的元素)求和，
        int ret = 0;
        for(int i=0;minT<n;){
            if(i<nums.size()&&nums[i]<=(minT+1)) minT+=nums[i++]; //nums[i]当前元素比minT+1小，意味着不用插入元素，并且更新当前求和，i++指向下一个元素
            else { //nums[i]比minT+1大，则表示从minT+1至nums[i]需要插入一个元素（所以res++），这里先插入的元素为minT+1，同时更新minT（将新插入的minT+1加进去）
               // cout<<minT+1<<endl;
                minT+=(minT+1);
                ret++;
            }
        }
        
        return ret;
    }
};
