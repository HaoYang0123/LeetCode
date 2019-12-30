//Leetcode 1299

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
