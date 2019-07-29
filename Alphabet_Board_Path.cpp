//Leetcode 1138

class Solution {
public:
    string alphabetBoardPath(string target) {
        unordered_map<int, pair<int,int>> c2pos;
		for(int i=0;i<26;++i) {
			int r=i/5;
			int c=i%5;
			c2pos[i]=pair<int,int>(r,c);
		}
		vector<vector<string>> dp(26, vector<string>(26, ""));
		for(int i=0;i<26;++i) {
			for(int j=0;j<26;++j) {
				pair<int, int> start=c2pos[i];
				pair<int, int> end=c2pos[j];
				int x=(start.first-end.first);
				int y=(start.second-end.second);
				string str1="", str2="";
				if(y<0) {
					y=-y;
					for(int k=0;k<y;++k) str1 += 'R';
				}
				else {
					for(int k=0;k<y;++k) str1 += 'L';
				}
				if(x<0) {
					x=-x;
					for(int k=0;k<x;++k) str2 += 'D';
				}
				else {
					for(int k=0;k<x;++k) str2 += 'U';
				}
                if(i!=25) dp[i][j] = str1+str2;
                else dp[i][j] = str2+str1;
			}
		}
		string res = "";
		int cur_pos = 0;
		for(int i=0;i<target.length();++i) {
			int new_pos = (int)(target[i]-'a');
			string move_str = dp[cur_pos][new_pos];
			res += move_str + "!";
			cur_pos = new_pos;
		}
		return res;
    }
};
