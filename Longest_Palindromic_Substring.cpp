//Leetcode 5

class Solution {
public:
	string longestPalindrome(string s) {
		int res = 0, start = 0, end = 0;
		for (int i = 0; i < s.length(); ++i) {
			int len_odd = get_palindrome_len(s, i, i);
			int len_even = get_palindrome_len(s, i, i + 1);
			int cur_len = max(len_odd, len_even);
			if (cur_len > res) {
				res = cur_len;
				start = i - (cur_len - 1) / 2;
				end = i + cur_len / 2;
			}
		}
		return s.substr(start, end - start + 1);
	}

	inline int get_palindrome_len(string & s, int left, int right) {
		while (left >= 0 && right < s.length() && s[left] == s[right]) {
			--left;
			++right;
		}
		return right - left - 1;
	}
};
