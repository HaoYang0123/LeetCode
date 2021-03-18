// Leetcode 1784

class Solution {
public:
	bool checkOnesSegment(string s) {
		int cur_seg = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '1') {
				if (i == 0 || s[i - 1] == '0') {
					++cur_seg;
					if (cur_seg > 1) return false;
				}
			}
		}
		return true;
	}
};
