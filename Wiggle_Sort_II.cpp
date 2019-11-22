//Leetcode 324
//这个题O(N）时间复杂，且O（1）空间，所以我分了好多情况来处理
//简单来讲：当nums[i]<nums[i+1]（即数字上升），但是需要下降时（i为奇数时），则将两个数字交换
//同理，当nums[i]>nums[i+1]但需要上升时，则也是将两个数字交换
//但是当nums[i]==nums[i+1]，则我分了两种情况：
//1）向后面继续找是不是有满足条件的，将nums[j]与nums[i]或者nums[i+1]交换
//2）如果没找到，则需要向前面找

class Solution {
public:
	void wiggleSort(vector<int> & nums) {
		int n = nums.size();
		for(int i=0;i<n-1;++i) {
			bool is_des = i%2; //i是偶数时,is_des是false表示上升，true表示下降
			if(nums[i] < nums[i+1] && is_des) { //表示当前数字上升，但是需要是下降时
				swap(nums[i], nums[i+1]); //只需要将两个数字交换，不用担心前面是否违反规则
			}
			else if(nums[i] > nums[i+1] && !is_des) {
				swap(nums[i], nums[i+1]);
			}
			else if(nums[i] == nums[i+1]) { //当两个数字相等时
				int starti = i;
				while(i<n-1&&nums[i]==nums[i+1]) ++i;
				//找到第1个与nums[i]不相等的元素
				if(i<n-1) { //如果找到了，可以将nums[i+1]与nums[starti]交换
					if(nums[i] > nums[i+1]) {
						if(is_des) swap(nums[starti+1], nums[i+1]);
						else swap(nums[starti], nums[i+1]);
					}
					else {
						if(is_des) swap(nums[starti], nums[i+1]);
						else swap(nums[starti+1], nums[i+1]);
					}
				}
				else { //如果没找到
					if(is_des) {
						//找到第1个满足要求的
						int j=starti-2;
						for(;j>=0;--j) {
							if(nums[j]>nums[starti]) {
								if(j % 2 == 1 && (j == 0 || nums[j-1]<nums[starti]) && nums[j+1]<nums[starti]) break;
								else if(j % 2 == 0 && (j == 0 || nums[j-1]>nums[starti]) && nums[j+1]>nums[starti]) break;
							}
						}
						if(j>=0) swap(nums[j], nums[starti]);
						else {
							j=starti-1;
							for(;j>=0;--j) {
								if(nums[j]<nums[starti+1]) {
									if(j % 2 == 0 && (j == 0 || nums[j-1]>nums[starti+1]) && nums[j+1]>nums[starti+1]) break;
									else if(j % 2 == 1 && (j == 0 || nums[j-1]<nums[starti+1]) && nums[j+1]<nums[starti+1]) break;
								}
							}
							if(j>=0) swap(nums[j], nums[starti+1]);
						}
					}
					else {
						int j=starti-2;
						for(;j>=0;--j) {
							if(nums[j]<nums[starti]) {
								if(j % 2 == 0 && (j == 0 || nums[j-1]>nums[starti]) && nums[j+1]>nums[starti]) break;
								else if(j % 2 == 1 && (j == 0 || nums[j-1]<nums[starti]) && nums[j+1]<nums[starti]) break;
							}
						}
						if(j>=0) swap(nums[j], nums[starti]);
						else {
							j=starti-1;
							for(;j>=0;--j) {
								if(nums[j]>nums[starti+1]) {
									if(j % 2 == 1 && (j == 0 || nums[j-1]<nums[starti+1]) && nums[j+1]<nums[starti+1]) break;
									else if(j % 2 == 0 && (j == 0 || nums[j-1]>nums[starti+1]) && nums[j+1]>nums[starti+1]) break;
								}
							}
							if(j>=0) swap(nums[j], nums[starti+1]);
						}
					}
				}
				i = starti;
			}
		}
	}
};
