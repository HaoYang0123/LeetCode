//Leetcode 1249

class Solution {
public:
	string minRemoveToMakeValid(string s) {
		stack<int> sta;
		int n=s.length();
		vector<bool> is_ok(n, true);
		for(int i=0;i<n;++i) {
			if(s[i] == '(') {
				sta.push(i);
			}
			else if(s[i] == ')') {
				if(sta.empty()) is_ok[i] = false;
				else {
					sta.pop();
				}
			}
		}
		while(!sta.empty()) {
			int ind = sta.top();
			sta.pop();
			is_ok[ind] = false;
		}
		string new_s = "";
		for(int i=0;i<n;++i) {
			if(is_ok[i]) new_s += s[i];
		}
		return new_s;
	}
};
