//Leetcode 1190

class Solution {
public:
	string reverseParentheses(string s) {
		stack<char> sta;
		for(int i=0;i<s.length();++i) {
			if(s[i] != ')') sta.push(s[i]);
			else {
				string new_s = "";
				while(!sta.empty()) {
					char c = sta.top();
					sta.pop();
					if(c == '(') break;
					new_s += c;
				}
				if(sta.empty() && i==s.length()-1) return new_s;
				for(int j=0;j<new_s.length();++j) sta.push(new_s[j]);
			}
		}
		string new_s = "";
		while(!sta.empty()) {
			char c = sta.top();
			sta.pop();
			if(c != '(') new_s += c;
		}
		reverse(new_s.begin(), new_s.end());
		return new_s;
	}
};
