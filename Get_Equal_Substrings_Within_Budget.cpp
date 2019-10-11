//Leetcode 1208
//滑动窗口

class Solution {
public:
	int equalSubstring(string s, string t, int maxCost) {
		int n = s.length();
		vector<int> data(n, 0);
		for(int i=0;i<n;++i) {
			data[i] = abs(int(s[i])-int(t[i]));
		}
		int res = 0;
		int left = 0, right = 0, curCost = maxCost;
		for(;right<n;++right) {
			curCost -= data[right];
			if(curCost < 0) {
				++left;
				curCost += data[left-1]; //当然有可能此时的curCost也是<0，不过没关系
			}
			res = max(res, (right-left+1));
		}
		return res;
	}
};
