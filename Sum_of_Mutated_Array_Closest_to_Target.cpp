//Leetcode 1300
//二分查找，minv为1，maxv为求和，根据二分来求解

class Solution {
public:
	int findBestValue(vector<int> & arr, int target) {
		int minv = 0, maxv = 0;
		int n = arr.size();
		for(int i=0;i<n;++i) maxv += arr[i];
		int abs_res = INT_MAX, res = -1;
		while(minv <= maxv) {
			int mid = minv + (maxv - minv) / 2;
			int v = get_value(arr, mid);
			if(abs(v - target) < abs_res) {
				abs_res = abs(v - target);
				res = mid;
			}
			if(v < target) minv = mid + 1;
			else if(v > target) maxv = mid - 1;
			else return mid;
		}
		return res;
	}
	inline int get_value(vector<int> & arr, int t) {
		int res = 0;
		for(int i=0;i<arr.size();++i) res += min(t, arr[i]);
		return res;
	}
};
