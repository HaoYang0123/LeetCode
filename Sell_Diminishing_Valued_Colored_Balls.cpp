//Leetcode 1648

class Solution {
public:
	int MOD = 1000000007;
	int maxProfit(vector<int> & inventory, int orders) {
		sort(inventory.rbegin(), inventory.rend());
		int min_v = 0, max_v = inventory[0];
		while (min_v <= max_v) {
			int mid = (min_v + (max_v - min_v) / 2);
			bool flag = is_bigger_order(inventory, mid, orders);
			if (flag) min_v = mid + 1; //如果当前order比orders大，所以<mid就不用考虑了
			else max_v = mid - 1;
		}
		vector<int> new_inv = inventory;
		for (int i = 0; i < new_inv.size(); ++i) {
			if (new_inv[i] <= min_v) break;
			orders -= (new_inv[i] - min_v);
			new_inv[i] = min_v;
		}
		for (int i = 0; i < orders; ++i) new_inv[i]--;
		long long res = 0;
		for (int i = 0; i < new_inv.size(); ++i) {
			if (new_inv[i] == inventory[i]) break;
			res += get_C(new_inv[i] + 1, inventory[i]);
			res %= MOD;
		}
		return res;
	}

	inline long long get_C(int a, int b) {
		//计算a,...b的和
		long long res = (long long)(a + b) * (b - a + 1) / 2;
		return res % MOD;
	}

	inline bool is_bigger_order(vector<int> & inventory, int v, int orders) {
		int cur_order = 0;
		for (int i = 0; i < inventory.size(); ++i) {
			if (inventory[i] <= v) break;
			cur_order += (inventory[i] - v);
			if (cur_order > orders) return true;
		}
		return false;
	}
};
