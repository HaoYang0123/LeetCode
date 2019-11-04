//Leetcode 1243

class Solution {
public:
	vector<int> transformArray(vector<int> & arr) {
		vector<int> res;
		bool flag = true;
		while(flag) {
			flag = false;
			res = arr;
			for(int i=1;i<arr.size()-1;++i) {
				if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
					res[i] = arr[i] - 1;
					flag = true;
				}
				else if(arr[i] < arr[i-1] && arr[i] < arr[i+1]) {
					res[i] = arr[i] + 1;
					flag = true;
				}
			}
			arr = res;
		}
		return res;
	}
};
