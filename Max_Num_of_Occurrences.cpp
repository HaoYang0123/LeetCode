//Leetcode 1297

class Solution {
public:
	int maxFreq(string s,int maxLetters, int minSize, int maxSize) {
		for(int l = minSize; l <= maxSize; ++l) {
			unordered_map<string, int> str2num;
			for(int i=0;i<s.length()-l+1;++i) {
				string subStr = s.substr(i, l);
				str2num[subStr] += 1;
			}
			int res = 0;
			for(auto ind = str2num.begin(); ind != str2num.end(); ++ind) {
				if(is_ok(ind->first, maxLetters)) res = max(res, ind->second);
			}
			if(res > 0)
				return res;
		}
		return 0;
	}
	inline bool is_ok(const string & str, int m) {
		unordered_set<char> ss;
		for(int i=0;i<str.length();++i) ss.insert(str[i]);
		return ss.size() <= m;
	}
};
