//Leetcode 55
//O(N)的时间复杂度，网上的代码。left表示当前处理的元素，right表示当前能够到达的最远距离
//如果right超过了数组大小，说明可以到达，返回true
//如果当left==right，则表示能够到达的最远距离已经与当前处理的位置一致，即永远也不可能到达数组末尾，返回false

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int left = 0, right = 0;
        int len = nums.size();
        while(right < len - 1){
            if(left + nums[left] > right)
                right = left + nums[left];
            else if(left == right)
                return false;
            left++;
        }
        return true;
    }
};
