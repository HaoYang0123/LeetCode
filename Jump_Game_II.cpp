//Leetcode 45
//O(N)的时间复杂度

//方法1：
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 0); //dp[i]表示从0到达i的最小步数
        for(int i=0;i<n;++i) dp[i] = i; //初始化，根据题意可以到达最终位置，那么结果肯定不会超过n
        int cur = 0; //当前位置
        for(int i=1;i<n;) {
            if(nums[cur]+cur>=i) { //假设当前位置cur，加上nums[cur]步数，超过了位置i
                dp[i] = min(dp[i], dp[cur]+1); //则更新位置i的最小步数为dp[cur]+1
                ++i;
            }
            else ++cur; //否则，将当前位置往后移，因为如果不移动当前位置，i及后面的位置一定到达不了
        }
        return dp[n-1];
    }
};


//方法2：使用栈来记录一组到达最远的位置（严格递增的顺序）
//可以将该题目看成是n个水平线（nums[i]表示从[i,i+nums[i]）的线段，找最小的线段数量，组合在一起可以覆盖[0,n-1]
class Solution {
public:
    int jump(vector<int>& nums) {
        stack<int> sta;
        int n=nums.size();
        if(n<=1) return 0;
        for(int i=0;i<nums.size();++i) {
            int c=i+nums[i];
            if(c>=n-1) {
                int old_c = -1;
                while(!sta.empty()&&sta.top()>=i) {
                    old_c = sta.top();
                    sta.pop();
                }
                if(old_c != -1)
                    return sta.size() + 2; //入old_c和c
                else return sta.size() + 1;
            }
            if(sta.empty()) sta.push(c);
            if(c>sta.top()) { //如果c比sta维护的最远位置还远，则更新sta
                int old_c = -1;
                while(!sta.empty()&&sta.top()>=i){ //需要之前的一些去除
                    old_c = sta.top();
                    sta.pop();
                }
                if(old_c != -1) sta.push(old_c);
                sta.push(c);
                cout<<c<<"\t"<<sta.size()<<endl;
            }
        }
        return 0;
    }
};
