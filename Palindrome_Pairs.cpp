//Leetcode 336

class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string> & words) {
		unordered_map<string, int> str2idx;
		for (int i = 0; i < words.size(); ++i) str2idx[words[i]] = i;
		vector<vector<int>> res;
		for (int i = 0; i < words.size(); ++i) {
			reverse(words[i].begin(), words[i].end());
			for (int j = 0; j <= words[i].length(); ++j) {
				string left = words[i].substr(0, j), right = words[i].substr(j);
				auto ind1 = str2idx.find(left), ind2 = str2idx.find(right);
				if (ind1 != str2idx.end() && is_palindrome(right) && ind1->second != i) 
					res.push_back({ind1->second, i});
				if (ind2 != str2idx.end() && is_palindrome(left) && ind2->second != i && j > 0) //注：这里j>0，因为需要防止重复
					res.push_back({ i, ind2->second });
			}
		}
		return res;
	}

	bool is_palindrome(string & str) {
		for (int i = 0; i < str.length() / 2; ++i) {
			if (str[i] != str[str.length() - 1 - i]) return false;
		}
		return true;
	}
};
