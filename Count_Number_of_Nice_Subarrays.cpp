//Leetcode 1248

class Solution {
public:
	int numberOfSubarrays(vector<int> & nums, int k) {
		unordered_map<int, int> oddCount2count;
		oddCount2count[0] = 1;
		int n=nums.size();
		int oddCount = 0;
		int res = 0;
		for(int i=0;i<n;++i) {
			if(nums[i] % 2 == 1) ++oddCount;
			oddCount2count[oddCount]++;
			int preOddCount = oddCount-k;
			if(preOddCount >= 0) {
				res += oddCount2count[preOddCount];
			}
		}
		return res;
	}
};
