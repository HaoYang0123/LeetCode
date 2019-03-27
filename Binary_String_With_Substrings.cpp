//Leetcode 1023
//因为S的长度最多是1000，那么可以枚举S的子串（最长不超过32，因为int是32位），计算S中所有子串对应的值，去填充[1,N]各元素，如果填满则返回true。

class Solution {
public:
    bool queryString(string S, int N) {
                unordered_map<int, bool> mm;
		int n=0;
		for(int i=0;i<S.length();++i)
		{
			long long bit = (long long)(S[i] - '0');
			if(bit >= 1 && bit <= N) {
				if(mm.find(bit) == mm.end()) {
					mm[bit] = true;
					++n;
					if(n == N) return true;
				}
			}
			for(int l=1;l<32&&i+l<S.length();++l) {
				long long c = (long long)(S[i+l] - '0');
				bit = (bit << 1) + c;
				if(bit > N) break;
				if(bit >= 1) {
					if(mm.find(bit) == mm.end()) {
						mm[bit] = true;
						++n;
						if(n == N) return true;
					}
				}
			}
		}
		return false;
    }
};
