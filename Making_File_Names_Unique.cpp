//Leetcode 1487

class Solution {
public:
	vector<string> getFolderNames(vector<string>& names) {
		unordered_map<string, int> name2num;
		vector<string> res(names.size(), "");
		for (int i = 0; i < names.size(); ++i) {
			string new_name = names[i];
			auto ind = name2num.find(new_name);
			int cur_ind = 1;
			if(ind != name2num.end()) cur_ind = ind->second;
			while (ind != name2num.end()) {
				new_name = names[i] + "(" + to_string(cur_ind++) + ")";
				ind = name2num.find(new_name);
			}
			name2num[names[i]]++; //之前没加这句，会超时，需要将原始的字符串进行更新
			name2num[new_name] = 1;
			res[i] = new_name;
		}
		return res;
	}
};
