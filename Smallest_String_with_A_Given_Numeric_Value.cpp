//Leetcode 1663
//最后的结果一定是"aaaXzzz"，其中只有一个字母X是a-z中的某个
//那么就相当于找X是在字符串中的哪个位置
//可以使用二分查找来完成

class Solution {
public:
	string getSmallestString(int n, int k) {
		int start = 0, end = n - 1, mid = 0, remain = 0;
		while (start <= end) {
			mid = (start + end) / 2;
			int left_v = mid;
			int right_v = (n - mid - 1) * 26;
			remain = k - left_v - right_v;
			if (remain >= 1 && remain <= 26) 
				break;
			else if (remain <= 0) start = mid + 1;
			else end = mid - 1;
		}
		string res = "";
		for (int i = 0; i < mid; ++i) res += 'a';
		res += char('a' + (remain - 1));
		for (int i = mid + 1; i < n; ++i) res += 'z';
		return res;
	}
};
