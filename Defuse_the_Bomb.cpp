//Leetcode 1652

class Solution {
public:
	vector<int> decrypt(vector<int> & code, int k) {
		if (k == 0) return vector<int>(code.size(), 0);
		int n = code.size();
		vector<int> sum(n, 0);
		sum[0] = code[0];
		for (int i = 1; i < n; ++i) sum[i] = sum[i - 1] + code[i];
		vector<int> res(n, 0);
		for (int i = 0; i < n; ++i) {
			int start, end;
			if (k > 0) {
				start = i + 1;
				end = i + k;
			}
			else {
				start = i + k;
				end = i - 1;
			}
			res[i] = get_sum(sum, n, start, end);
			cout << start << "\t" << end << "\t" << res[i] << endl;
		}
		return res;
	}

	inline int get_sum(vector<int> & sum, int n, int start, int end) {
		if (start >= 0 && start < n && end >= 0 && end < n) {
			int e = 0;
			if (start - 1 >= 0) e = sum[start - 1];
			return sum[end] - e;
		}
		if (start >= 0 && start < n && end >= n) {
			end %= n;
			int e = 0;
			if (start - 1 >= 0) e = sum[start - 1];
			return sum[end] + sum[n - 1] - e;
		}
		if (start < 0 && end >= 0 && end < n) {
			start += n;
			int e = 0;
			if (start - 1 >= 0) e = sum[start - 1];
			return sum[end] + sum[n - 1] - e;
		}
		if (start >= n) {
			start %= n;
			end %= n;
			int e = 0;
			if (start - 1 >= 0) e = sum[start - 1];
			return sum[end] - e;
		}
		if (end < 0) {
			start += n;
			end += n;
			int e = 0;
			if (start - 1 >= 0) e = sum[start - 1];
			return sum[end] - e;
		}
		return 0;
	}
};
