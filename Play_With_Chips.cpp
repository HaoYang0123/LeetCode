//Leetcode 1217

class Solution {
public:
	int minCostToMoveChips(vector<int> & chips) {
		vector<int> odd_even(2, 0);
		for(int i=0;i<chips.size();++i) {
			odd_even[chips[i] % 2]++;
		}
		return min(odd_even[0], odd_even[1]);
	}
};
