//Leetcode 75

class Solution {
public:
	void sortColors(vector<int> & nums) {
		int l=0,r=nums.size()-1; //l和r分别表示左、右两头索引
		int i=0; //i表示当前位置
		while(i<=r) {
			if(nums[i] == 1) ++i; //如果nums[i]等于1，则向右移动
			else if(nums[i] == 0) swap(nums[i++], nums[l++]); //nums[i]等于0，则可以与l交换，并更新l和i（注：这里需要更新i，否则会死循环，为何可以更新i是因为nums[l]一定等于1）
			else swap(nums[i], nums[r--]); //nums[i]等于2，则与r交换，只更新r
		}
	}
};
