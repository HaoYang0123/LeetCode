//Leetcode 1209
//使用栈来操作，记录上一个字符及出现的次数

class Solution {
public:
	string removeDuplicates(string s, int k) {
		string res = "";
		stack<pair<char, int>> sta;
		sta.push(pair<char,int>(s[0], 1));
		for(int i=1; i<s.length(); ++i) {
			if(sta.empty()) sta.push(pair<char,int>(s[i], 1));
			else {
				pair<char, int> tt = sta.top();
				if(tt.first != s[i]) {
					sta.push(pair<char,int>(s[i], 1));
				}
				else {
					sta.pop();
					if(tt.second + 1 < k) {
						sta.push(pair<char,int>(s[i], tt.second+1));
					}
				}
			}
		}
		vector<string> rrr;
		while(!sta.empty()) {
			string one_c = "";
			pair<char, int> tt = sta.top();
			sta.pop();
			for(int i=0;i<tt.second;++i) one_c += tt.first;
			rrr.push_back(one_c);
		}
		for(int i=rrr.size()-1;i>=0;--i) res += rrr[i];
		return res;
	}
};
