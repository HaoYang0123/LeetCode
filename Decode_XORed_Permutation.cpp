// Leetcode 1734

class Solution {
public:
	vector<int> decode(vector<int>& encoded) {
		int xor_A = 0;
		for(int i=1;i<encoded.size();i+=2) {
			xor_A ^= encoded[i];
		}
		int xor_all = 0;
		for(int i=1;i<=encoded.size()+1;++i) {
			xor_all ^= i;
		}
		vector<int> res(encoded.size()+1, 0);
		res[0] = xor_A ^ xor_all;
		for(int i=1;i<res.size();++i) {
			res[i] = res[i-1] ^ encoded[i-1];
		}
		return res;
	}
};
