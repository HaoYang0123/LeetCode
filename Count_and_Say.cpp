//Leetcode 38

class Solution {
public:
	string countAndSay(int n) {
		string res = "1";
		for(int i=2;i<=n;++i) {
			res = next_string(res);
		}
		return res;
	}
	string next_string(string & prev) {
		char c = prev[0];
		int n = 1;
		string res = "";
		for(int i=1;i<prev.length();++i) {
			if(prev[i] == c) ++n;
			else {
				res += to_string(n) + c;
				c = prev[i];
				n = 1;
			}
		}
		res += to_string(n) + c;
		return res;
	}
};
