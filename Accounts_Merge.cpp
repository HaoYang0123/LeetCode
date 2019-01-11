//Leetcode 721
//先构建“图”，然后在图中计算连通图。连通的图对应于一个用户，多少个连通图就有多少个用户

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, vector<int>> mm; //email->multiple indexes
		int n = accounts.size();
		vector<string> names(n, "");
		for(int i=0;i<n;++i) {
			names[i] = accounts[i][0];
			for(int j=1;j<accounts[i].size();++j) {
				string email = accounts[i][j];
				mm[email].push_back(i);
			}
		}
		vector<int> dp(n, 0);
		for(int i=0;i<n;++i) dp[i] = i;
		for(auto ind = mm.begin(); ind != mm.end(); ++ind) {
			vector<int> edges = ind->second;
			for(int i = 1; i < edges.size(); ++i) update_dp(dp, dp[edges[0]], dp[edges[i]]);
		}
		vector<vector<string>> res;
		unordered_map<string, bool> is_in;
		vector<int> ind_ind(n, 0);
		for(int i=0;i<n;++i) {
			if(dp[i] == i) { //the first one
                vector<string> tmp;
                tmp.push_back(accounts[i][0]);
                for(int j=1;j<accounts[i].size();++j) {
					if(is_in.find(accounts[i][j]) == is_in.end()) {
						is_in[accounts[i][j]] = true;
						tmp.push_back(accounts[i][j]);
					}
				}
				res.push_back(tmp);
				ind_ind[i] = res.size()-1;
			}
			else { //others, dp[i] < i
				int ind = ind_ind[dp[i]];
				for(int j=1;j<accounts[i].size();++j) {
					if(is_in.find(accounts[i][j]) == is_in.end()) {
						is_in[accounts[i][j]] = true;
						res[ind].push_back(accounts[i][j]);
					}
				}
			}
		}
		for(int i=0;i<res.size();++i) {
			sort(res[i].begin()+1, res[i].end());
		}
		return res;   
    }
    void update_dp(vector<int> & dp, int s, int k) { //s<k
        if(s>k) {
            int t = s;
            s = k;
            k = t;
        }
		for(int i=0;i<dp.size();++i) {
			if(dp[i]==k) dp[i]=s;
		}
	}
};
