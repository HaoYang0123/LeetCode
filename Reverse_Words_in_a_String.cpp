//Leetcode 151

class Solution {
public:
	string reverseWords(string s) {
		vector<string> words;
		string cur_word = "";
		for(int i=0; i<s.length(); ++i) {
			if(s[i] == ' ') {
				if(cur_word != "") {
					words.push_back(cur_word);
					cur_word = "";
				}
			}
			else cur_word += s[i];
		}
		if(cur_word != "") words.push_back(cur_word);
		if(words.size() == 0) return "";
		for(int i=0;i<words.size()/2;++i) {
			swap(words[i], words[words.size()-1-i]);
		}
		string res = "";
		for(int i=0;i<words.size()-1;++i) res += words[i] + " ";
		res += words[words.size()-1];
		return res;
	}
};
