//Leetcode 1363
//超内存了，可能需要改一下dp3，只存储上一个数字的索引号

class Solution {
public:
	string largestMultipleOfThree(vector<int>& digits) {
		sort(digits.begin(), digits.end(), greater<int>());
		int n = digits.size();
		vector<vector<int>> dp(n, vector<int>(3, 0));
		//dp[i][j]为从[0,i](包含i)的求和余数等于j的最大数量
		vector<vector<int>> dp2(n, vector<int>(3, 0));
		//dp2[i][j]为从[0,i](不一定包含i)的求和余数等于j的最大数量
		//vector<vector<vector<int>>> dp3(n, vector<vector<int>>(3, vector<int>()));
		vector<vector<int>> dp3(3, vector<int>());
		//dp3[i]存储求和余数等于i的最大数量对应的数字
		dp[0][digits[0] % 3] = 1;
		dp2[0][digits[0] % 3] = 1;
		dp3[digits[0] % 3] = vector<int>({ digits[0] });
		for (int i = 1; i < n; ++i) {
			int rem = digits[i] % 3;
			vector<vector<int>> new_dp3(3, vector<int>());
			for (int j = 0; j < 3; ++j) {
				int newJ = (j + rem) % 3;
				if (j != 0 && dp2[i - 1][j] == 0 && dp2[i - 1][newJ] == 0) continue;
				dp[i][newJ] = dp2[i - 1][j] + 1;
				if (dp[i][newJ] > dp2[i - 1][newJ]) {
					dp2[i][newJ] = dp[i][newJ];
					new_dp3[newJ] = dp3[j];
					new_dp3[newJ].push_back(digits[i]);
				}
				else {
					dp2[i][newJ] = dp2[i - 1][newJ];
					new_dp3[newJ] = dp3[newJ];
				}
			}
			dp3 = new_dp3;
		}
		//write(dp2, dp3, n-2);
		//cout<<"====="<<endl;
		//write(dp2, dp3, 1);
		vector<int> & res_vec = dp3[0];
		if (res_vec.size() == 0) return "";
		int i = 0;
		while (i < res_vec.size() && res_vec[i] == 0) ++i;
		if (i == res_vec.size()) return "0";
		string res = "";
		while (i < res_vec.size()) {
			res += char('0' + res_vec[i]);
			++i;
		}
		return res;
	}

	inline void write(vector<vector<int>> & dp2, vector<vector<int>> & dp3, int index) {
		cout << "------0------\t" << dp2[index][0] << endl;
		for (int i = 0; i < dp3[0].size(); ++i) cout << dp3[0][i] << "\t";
		cout << endl << "------1------\t" << dp2[index][1] << endl;
		for (int i = 0; i < dp3[1].size(); ++i) cout << dp3[1][i] << "\t";
		cout << endl << "------2------\t" << dp2[index][2] << endl;
		for (int i = 0; i < dp3[2].size(); ++i) cout << dp3[2][i] << "\t";
		cout << endl;
	}
};
