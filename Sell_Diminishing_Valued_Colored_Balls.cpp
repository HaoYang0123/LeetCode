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
		//比如：[7,7,6,4,2,2]，orders=10
		//最后需要转化为：[3,3,4,4,2,2]，这里min_v就相当于4
		//首先先用new_inv将原数组保存，然后将所有>min_v的转化为min_v（即[4,4,4,4,2,2]）
		vector<int> new_inv = inventory;
		for (int i = 0; i < new_inv.size(); ++i) {
			if (new_inv[i] <= min_v) break;
			orders -= (new_inv[i] - min_v);
			new_inv[i] = min_v;
		}
		//消耗了8个order，还剩余2个，直接将前两个元素-1即可
		//最终得到[3,3,4,4,2,2]
		for (int i = 0; i < orders; ++i) new_inv[i]--;
		long long res = 0;
		//最后计算结果：第1个元素从7变为了3，相当于花了4个order，得到7+6+5+4
		//其它元素依次类推...
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
