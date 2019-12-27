//Leetcode 3
//O(N)时间复杂度，记录[start,end]的子串，拥有不同的字符

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int start = 0, end = 0;
		int res = 0;
		unordered_map<char, int> c2ind;
		while(end<s.length()) {
			auto ind = c2ind.find(s[end]);
			if(ind != c2ind.end()) { //如果当前字符之前存在，则更新start
				start = max(start, ind->second+1);
			}
			c2ind[s[end]] = end; //更新距离end最近的s[end]字符的位置
			res = max(res, end-start+1); //[start,end]为当前的最长子串
			++end;
		}
		return res;
	}
};
