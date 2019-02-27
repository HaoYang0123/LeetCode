//Leetcode 1001

class Solution {
public:
	vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> r, c, dia1, dia2; //分别存储行、列、正对角线、反对角线的被点亮的次数
		unordered_map<int, unordered_set<int>> lights; //记录所有灯的位置，用于后续检查是否熄灭了灯
		for(int i=0;i<lamps.size();++i) {
			int a=lamps[i][0], b=lamps[i][1];
			r[a]++;
			c[b]++;
			dia1[a+b]++;
			dia2[a-b]++;
            lights[a].insert(b);
		}
		vector<int> res;
		int n_step[] = {-1,-1,-1,0,0,0,1,1,1};
		int c_step[] = {-1,0,1,-1,0,1,-1,0,1};
		for(int i=0;i<queries.size();++i) {
			int a=queries[i][0], b=queries[i][1];
			if(r[a]>0 || c[b]>0 || dia1[a+b]>0 || dia2[a-b]>0) { 
				res.push_back(1);
				//考虑周围九个位置，如果有灯，那么将其熄灭，并将对应的行、列、正负对角线的次数减1
				for(int s=0;s<9;++s) {
					int n_a=a+n_step[s], n_b=b+c_step[s];
					if(lights[n_a].erase(n_b)) { //找到灯，则更新，使用erase来删除某个值，如果不存在返回False，存在则删除对应值并返回True
						r[n_a]--;
						c[n_b]--;
						dia1[n_a+n_b]--;
						dia2[n_a-n_b]--;
					}
				}
			}
			else res.push_back(0);
		}
		return res;
	}
};
