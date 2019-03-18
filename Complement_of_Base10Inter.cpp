//Leetcode 1012
//两种方法，第二种方法使用异或运算，比如5的二进制是：101，那么101^111=010=2

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int bitwiseComplement_old(int N) {
		if(N==0) return 1;
		vector<int> bs;
		while(N>0) {
			bs.push_back(N%2);
			N=N>>1;
		}
		int res=0, bit=1;
		for(int i=0;i<bs.size();++i) {
			int c=bs[i];
			if(c==0) c=1;
			else c=0;
			res += (bit*c);
			bit = bit<<1;
		}
		return res;
	}
	int bitwiseComplement(int N) {
		if(N==0) return 1;
		int r = 0, bit = 1;
		int n = N;
		while(n>0) {
			r += bit;
			bit = bit<<1;
			n = n>>1;
		}
		return N ^ r;
	}
};

int main() {
	Solution s;
	int res = s.bitwiseComplement(10);
	cout<<res<<endl;
	return 0;
}
