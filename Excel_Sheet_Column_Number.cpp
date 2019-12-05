//Leetcode 171

class Solution {
public:
	int titleToNumber(string s) {
		long long res = 0, mul = 1;
		for(int i=s.length()-1;i>=0;--i) {
			int bit = int(s[i]-'A')+1;
			res += mul * bit;
			mul *= 26;
		}
		return res;
	}
};
