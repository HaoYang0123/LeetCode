//Leetcode 1291

class Solution {
public:
	vector<int> sequentialDigits(int low, int high) {
		int low_bit_num = get_bit_num(low);
		int high_bit_num = get_bit_num(high);
		high_bit_num = min(high_bit_num, 9);
		unordered_map<int,int> bitnum2value, bitnum2add;
		bitnum2value[0] = 0;
		bitnum2value[1] = 1;
		bitnum2value[2] = 12;
		bitnum2value[3] = 123;
		bitnum2value[4] = 1234;
		bitnum2value[5] = 12345;
		bitnum2value[6] = 123456;
		bitnum2value[7] = 1234567;
		bitnum2value[8] = 12345678;
		bitnum2value[9] = 123456789;
		init(bitnum2add);

		vector<int> res;
		if(low_bit_num > 9) return res;
		for(int b = low_bit_num; b <= high_bit_num; ++b) {
			int low_value = bitnum2value[b], add = bitnum2add[b];
			for(int v = low_value; ; v += add) {
				if(v >= low && v <= high) res.push_back(v);
				if(v > high) break;
				if(v % 10 == 9) break;
			}
		}
		return res;
	}

	inline void init(unordered_map<int, int> & b2add) {
		b2add[0] = 1;
		for(int i=1;i<=9;++i) {
			int r = 0, m = 1;
			for(int j=1;j<=i;++j) {
				r += m;
				m *= 10;
			}
			b2add[i] = r;
		}
	}

	inline int get_bit_num(int value) {
		int res = 0;
		while(value > 0) {
			res++;
			value /= 10;
		}
		return res;
	}
};
