//Leetcode 1295

class Solution {
public:
	int findNumbers(vector<int> & nums) {
		int res = 0;
		for(int i=0;i<nums.size();++i) {
			if(get_bit(nums[i]) % 2 == 0) ++res;
		}
		return res;
	}
	inline int get_bit(int n) {
		int bit_num = 0;
		while(n>0) {
			++bit_num;
			n /= 10;
		}
		return bit_num;
	}
};
