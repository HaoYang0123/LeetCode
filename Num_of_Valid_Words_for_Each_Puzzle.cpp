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

//方法2：网上的代码，位运算
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        // Lengths
        int P = puzzles.size();
        int W = words.size();
        
        // Letter masks
        vector<int> letterMask(26, 0); //相当于'a'表示为1,'b'表示为10,'c'表示为100
        
        for (int i = 0, mask = 1; i < 26; ++i, mask <<= 1) {
            letterMask[i] = mask;
        }
        
        // Word masks with count info
        unordered_map<int, int> wordsMask;
        
        // For each word
        for (int i = 0; i < W; ++i) {
            // Compute word mask
            int mask = 0; //mask表示words[i]对应的hash值，只有“相同”字符串的才有相同的hash值
			//这里的“相同”表示为"abc"和"cba"也认为是“相同”
            
            for (char c: words[i]) {
                mask = mask | letterMask[c - 'a'];
            }
            
            ++wordsMask[mask];
        }
       
         // Result : result[i] => number of words covered by puzzles[i]
        vector<int> result(P, 0); 
        
        // For each puzzle
        for (int i = 0; i < P; ++i) {
            // Compute puzzle mask
            int mask = 0; //mask表示为puzzles[i]对应的hash值
            
            for (char c: puzzles[i]) {
                mask = mask | letterMask[c - 'a'];
            }
            
            // Iterate through all valid subset of mask i.e. subset of puzzle chars = 2^7 = 64 in count
            // This makes the complexity O(P*64)
            int subMask = mask;
            
            while (subMask) {
                if ((subMask & letterMask[puzzles[i][0] - 'a']) && wordsMask.count(subMask)) {
                    result[i] += wordsMask[subMask];
                }
                
                // Only select valid bits i.e. bits corresponding to chars in puzzle
                subMask = (subMask - 1) & mask; //枚举mask位数为1的情况，比如"111"有八种情况：2^3=8
            }
        }
        
        return result;
    }
};
