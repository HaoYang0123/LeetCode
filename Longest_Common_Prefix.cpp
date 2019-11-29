//Leetcode 14
//字典树

class Point{
public:
	char c;
	vector<Point*> child;
	bool is_leaf;
public:
	Point(char c) {
		this->c = c;
		this->child.resize(26, NULL);
		this->is_leaf = false;
	}
};

class Solution {
public:
	string longestCommonPrefix(vector<string> & strs) {
		if(strs.size() == 0) return "";
		if(strs.size() == 1) return strs[0];
		vector<Point*> root(26, NULL);
		for(int i=0; i<strs.size(); ++i) {
			string & one_str = strs[i];
			if(one_str.length() == 0) return "";
			if(root[int(one_str[0]-'a')] == NULL) root[int(one_str[0]-'a')] = new Point(one_str[0]);
			Point* cur_point = root[int(one_str[0]-'a')];
			for(int j=1; j<one_str.length(); ++j) {
				vector<Point*> & child = cur_point->child;
				int ind = int(one_str[j] - 'a');
				if(child[ind] == NULL) child[ind] = new Point(one_str[j]);
				cur_point = child[ind];
			}
			cur_point->is_leaf = true;
		}
		string res = "";
		vector<Point*> & cur_root = root;
		while(true) {
			int c = 0;
			Point* cur_point = NULL;
			for(int i=0;i<26;++i) {
				if(cur_root[i] != NULL) {
					++c;
					cur_point = cur_root[i];
				}
			}
			if(c!=1) break;
			res += cur_point->c;
			if(cur_point->is_leaf) break;
			cur_root = cur_point->child;
		}
		return res;
	}
};
