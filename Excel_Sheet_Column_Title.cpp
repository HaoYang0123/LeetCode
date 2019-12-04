//Leetcode 168

class Solution {
public:
	string convertToTitle(int n) {
		string res = "";
		while(n > 0) {
			res += ((n - 1) % 26 + 'A');
			n = (n - 1) / 26;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
