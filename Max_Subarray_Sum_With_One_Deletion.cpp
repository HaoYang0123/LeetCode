//Leetcode 1186

class Solution {
public:
	int maximumSum(vector<int>& arr) {
		int a=arr[0],b=arr[0]; //防止arr如果全为负数，返回0的结果。a和b分别表示不删除和删除1个元素的最大求和值
		int res=arr[0];
		for(int i=1;i<arr.size();++i) {
			if(arr[i] >= 0) {
				int a2 = a + arr[i];
				a = max(arr[i], a2);
				b = max(arr[i], b + arr[i]);
				res = max(res, a);
				res = max(res, b);
			}
			else {
				int a2 = a + arr[i];
				b = max(b + arr[i], a);
				a = max(arr[i], a2);
				res = max(res, a);
				res = max(res, b);
			}
		}
		return res;
	}
};
