//Leetcode 87

class Solution {
public:
    bool isScramble(string s1, string s2) {
		return dfs(s1, 0, s1.length()-1, s2, 0, s2.length()-1);
    }
	bool dfs(string & s1, int start1, int end1, string & s2, int start2, int end2) {
		if(end1-start1 != end2-start2) return false;
		unordered_map<char, int> m;
		for(int i=start1;i<=end1;++i) m[s1[i]]++;
		for(int i=start2;i<=end2;++i) {
			if(m.find(s2[i]) == m.end()) return false;
			m[s2[i]]--;
			if(m[s2[i]] < 0) return false;
		}
		if(end1 - start1 <= 2) return true; //长度为3的结果一定是正确的
		for(int i=start1;i<end1;++i) {
			int j = start2+(i-start1);
			bool flag = dfs(s1, start1, i, s2, start2, j);
			if(flag) {
				bool flag2 = dfs(s1, i+1, end1, s2, j+1, end2);
				if(flag2) return true;
			}
			j = end2-(i-start1);
			flag = dfs(s1, start1, i, s2, j, end2);
			if(flag) {
				bool flag2 = dfs(s1, i+1, end1, s2, start2, j-1);
				if(flag2) return true;
			}
		}
		return false;
	}
};
