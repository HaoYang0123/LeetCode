//Leetcode 316
//贪心策略

class Solution {
public:
	string removeDuplicateLetters(string s) {
		vector<int> c2n(26, 0);
		vector<bool> is_in(26, false); 
		for(int i=0;i<s.length();++i) c2n[int(s[i]-'a')]++;
		string res = "";
		for(int i=0;i<s.length();++i) {
			int ind = int(s[i]-'a');
			if(is_in[ind]) continue;
			if(c2n[ind] == 1) {
				res += s[i];
				is_in[ind] = true;
			}
			else {
				char ori_c = s[i];
				int ori_i = i;
				while(i<s.length()) {
					if(is_in[int(s[i]-'a')]) {
						++i;
						continue;
					}
					if(s[i] < ori_c || c2n[int(s[i]-'a')] == 1) break;
					--c2n[int(s[i]-'a')];
					++i;
				}
				if(i<s.length() && s[i] < ori_c) {
					//for(int j=ori_i;j<i;++j) --c2n[int(s[j]-'a')];
					--i;
				}
				else {
					for(int j=ori_i;j<i;++j) ++c2n[int(s[j]-'a')];
					res += ori_c;
					is_in[int(ori_c-'a')] = true;
					i = ori_i;
				}
			}
		}
		return res;
	}
};
