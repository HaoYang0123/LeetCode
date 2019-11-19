//Leetcode 238

class Solution {
public:
	vector<int> productExceptSelf(vector<int> & nums) {
		//根据题目要求不能使用除法，且不能另开数组（即空间复杂度为O(1)）
		//假设没有空间复杂度要求，则可以开两个数组：分别存储前向累积乘法值和后向累积乘法值
		//比如：nums = {1,2,3,4}
		//则data1 = {1,2,6,24}和data2 = {24,24,12,4}
		//这样res[i] = data1[i-1]*data2[i+1]（当i>=1&&i<=n-2时）
		//不另开数组，则直接使用res来处理，代码如下（思路就是上面的思路）
		int n = nums.size();
		vector<int> res(n, 1);
		for(int i=1;i<n;++i) res[i] = res[i-1]*nums[i-1]; //当前先存储正向的(但不包含本身)
		//比如上面例子：{1,2,3,4}，那么现在的res = {1,1,2,6}
		int cur_p = nums[n-1]; //cur_p表示后向的累积乘
		for(int i=n-2;i>=0;--i) {
			res[i] = res[i] * cur_p;
			cur_p *= nums[i];
		}
		return res;
	}
};
