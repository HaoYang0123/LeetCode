//Leetcode 1268
//字典树

class Point {
public:
	char c;
	vector<Point *> child;
	string whole_string;

public:
	Point() {}
	Point(char c) {
		this->c = c;
		this->child.resize(26, NULL);
		this->whole_string = "";
	}
};

class Solution {
public:
	vector<vector<string>> suggestedProducts(vector<string> & products, string searchWord) {
		vector<vector<string>> res;
		vector<Point*> root(26, NULL); //root为字典树的根结点
		for(int i=0; i<products.size(); ++i) { //枚举所有的product名字
			string & name = products[i];
			if(root[int(name[0]-'a')] == NULL) root[int(name[0]-'a')] = new Point(name[0]);
			Point* cur_point = root[int(name[0]-'a')];
			for(int j=1; j<name.length(); ++j) { //将name[j]插入到字典树中的对应位置
				if(cur_point->child[int(name[j]-'a')] == NULL) cur_point->child[int(name[j]-'a')] = new Point(name[j]);
				cur_point = cur_point->child[int(name[j]-'a')];
			}
			cur_point->whole_string = name; //使用whole_string来表示字典树中从root至当前结点组成的路径为products中的一个name
		}
		vector<Point*> cur_root = root;
		int i=0;
		for(;i<searchWord.size();++i) { //搜索词
			Point* cur_point = cur_root[int(searchWord[i]-'a')];
			if(cur_point == NULL) break; //如果搜索词的前i个字符串没有products是其前缀（即cur_point=NULL），则break
			vector<string> cur_res;
			get_product(cur_point, cur_res); //深度搜索前3个前缀字符串
			res.push_back(cur_res);
			cur_root = cur_point->child;
		}
		for(;i<searchWord.size();++i) res.push_back(vector<string>());
		return res;
	}

	void get_product(Point * cur_point, vector<string> & res, int num=3) {
		if(res.size() >= num) return;
		if(cur_point->whole_string != "") {
			res.push_back(cur_point->whole_string);
			if(res.size() >= num) return;
		}
		vector<Point*> & child = cur_point->child;
		for(int i=0;i<child.size();++i) {
			if(child[i] == NULL) continue;
			get_product(child[i], res, num);
		}
	}
};
