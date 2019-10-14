//Leetcode 1221
//时间复杂度为O(N)

class Solution {
public:
	int balancedStringSplit(string s) {
		int n = s.length();
		int curl = 0, curr = 0, res = 0;
		for(int i=0;i<n;++i) {
			if(s[i]=='L') ++curl;
			else ++curr;
			if(curl == curr) ++res;
		}
		return res;
	}
};
