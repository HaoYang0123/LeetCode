//Leetcode 1282

class Solution {
public:
	vector<vector<int>> groupThePeople(vector<int> & groupSizes) {
		unordered_map<int, vector<int>> num2index;
		for(int i=0;i<groupSizes.size();++i) {
			num2index[groupSizes[i]].push_back(i);
		}
		vector<vector<int>> res;
		for(auto ind = num2index.begin(); ind != num2index.end(); ++ind) {
			vector<int> & index = ind->second;
			int num = ind->first;
			vector<int> one_group;
			for(int i=0;i<index.size();++i) {
				one_group.push_back(index[i]);
				if(one_group.size() >= num) {
					res.push_back(one_group);
					one_group.clear();
				}
			}
		}
		return res;
	}
};
