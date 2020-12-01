//Leetcode 1657

class Solution {
public:
	bool closeStrings(string word1, string word2) {
		int n1 = word1.length(), n2 = word2.length();
		if (n1 != n2) return false;
		map<char, int> u1, u2;
		vector<int> v1, v2;
		get_vec(word1, u1, v1);
		get_vec(word2, u2, v2);
		if (u1.size() != u2.size()) return false;
		for (auto ind1 = u1.begin(), ind2 = u2.begin(); ind1 != u1.end(); ++ind1, ++ind2) {
			if (ind1->first != ind2->first) return false;
		}
		if (v1.size() != v2.size()) return false;
		for (int i = 0; i < v1.size(); ++i) {
			if (v1[i] != v2[i]) return false;
		}
		return true;
	}

	inline void get_vec(string & word, map<char, int> & u, vector<int> & v) {
		for (int i = 0; i < word.length(); ++i) {
			u[word[i]]++;
		}
		for (auto ind = u.begin(); ind != u.end(); ++ind) {
			v.push_back(ind->second);
		}
		sort(v.begin(), v.end());
	}
};
