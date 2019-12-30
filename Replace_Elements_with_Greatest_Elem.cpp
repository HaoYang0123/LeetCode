//Leetcode 1299

//方法1：从右往左扫描，记录当前最大值
class Solution {
public:
	vector<int> replaceElements(vector<int> & arr) {
		int n = arr.size();
		vector<int> res(n, -1);
		int max_v = arr[n-1];
		for(int i=n-2;i>=0;--i) {
			res[i] = max_v;
			max_v = max(max_v, arr[i]);
		}
		return res;
	}
};

//方法2：使用map记录各值对应的位置
class Solution {
public:
	vector<int> replaceElements(vector<int> & arr) {
		map<int, int> v2pos;
		for(int i=0;i<arr.size();++i) v2pos[arr[i]] = i;
		vector<int> res(arr.size(), -1);
		int i=0;
		while(i<arr.size()-1) {
			auto ind = v2pos.rbegin();
			int max_pos = ind->second;
			for(;i<max_pos;++i) res[i] = ind->first;
			v2pos.erase(ind->first);
		}
		return res;
	}
};
