//Leetcode 1178

//方法1：超时
class Solution {
public:
	vector<int> findNumOfValidWords(vector<string> & words, vector<string> & puzzles) {
		vector<vector<int>> dp(26, vector<int>()); //dp[i]表示包含字母'a'+i的索引位置
		int n=words.size(), m=puzzles.size();
		vector<int> word_len(n, 0);
		for(int i=0;i<n;++i) {
			string & word = words[i];
			unordered_set<int> ss;
			for(int j=0;j<word.length();++j) ss.insert(int(word[j]-'a'));
			word_len[i] = ss.size();
			for(auto ind = ss.begin(); ind != ss.end(); ++ind) dp[*ind].push_back(i);
		}
		vector<int> res(m, 0);
		for(int i=0;i<m;++i) {
			string & puz = puzzles[i];
			unordered_map<int, int> index2num;
			for(int j=0;j<puz.length();++j) {
				int ind = int(puz[j]-'a');
				vector<int> & word_index = dp[ind];
				for(int k=0;k<word_index.size();++k) index2num[word_index[k]]++;
			}
			vector<int> & firstIndex = dp[puz[0]-'a'];
			int cur_res = 0;
			for(int j=0;j<firstIndex.size();++j) {
				int ind = firstIndex[j];
				if(word_len[ind] == index2num[ind]) ++cur_res;
			}
			res[i] = cur_res;
		}
		return res;
	}
};
