//Leetcode 1298
//宽度搜索，只有获取到了key及box时，才能打开该box

class Solution {
public:
	int maxCandies(vector<int> & status, vector<int> & candies, vector<vector<int>> & keys, vector<vector<int>> & containedBoxes, vector<int> & initialBoxes) {
		int n = status.size();
		vector<bool> is_vis(n, false);
		vector<int> has_contain(n, 0);
		queue<int> qs;
		int res = 0;
		for(int i = 0; i < initialBoxes.size(); ++i) {
			int b = initialBoxes[i];
			has_contain[b] = 1;
			if(status[b] == 1) {
				is_vis[b] = true;
				qs.push(b);
			}
		}
		while(!qs.empty()) {
			int b = qs.front();
			qs.pop();
			res += candies[b];
			vector<int> & has_key = keys[b];
			vector<int> & contain = containedBoxes[b];
			vector<int> can_open;
			for(int i = 0; i < has_key.size(); ++i) {
				int k = has_key[i];
				status[k] = 1;
				if(has_contain[k] == 1 && !is_vis[k]) can_open.push_back(k); 
			}
			for(int i = 0; i < contain.size(); ++i) {
				int k = contain[i];
				has_contain[k] = 1;
				if(status[k] == 1 && !is_vis[k]) can_open.push_back(k);
			}
			for(int i = 0; i < can_open.size(); ++i) {
				qs.push(can_open[i]);
				is_vis[can_open[i]] = true;
			}
		}
		return res;
	}
};
