// Leetcode 1839

class Solution {
public:
	int longestBeautifulSubstring(string word) {
		int i = 0, j = 0;
		int res = 0;
		while (j < word.length()) {
			if (i == j) {  //字符串开始
				if (word[i] == 'a') ++j;
				else {
					i = j + 1;
					j = i;
				}
			}
			else {
				if (word[j] == word[j - 1] || is_next(word[j - 1], word[j])) {
					if (word[j] == 'u')
						res = max(res, j - i + 1);
					++j;
				}
				else {
					i = j;
				}
			}
		}
		return res;
	}

	inline bool is_next(char a, char b) {
		if (a == 'a' && b == 'e') return true;
		if (a == 'e' && b == 'i') return true;
		if (a == 'i' && b == 'o') return true;
		if (a == 'o' && b == 'u') return true;
		return false;
	}
};
