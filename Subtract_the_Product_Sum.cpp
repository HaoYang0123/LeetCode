//Leetcode 1281

class Solution {
public:
	int subtractProductAndSum(int n) {
		int mul = 1, sum = 0;
		while(n > 0) {
			int bit = n % 10;
			mul *= bit;
			sum += bit;
			n /= 10;
		}
		return mul - sum;
	}
};
