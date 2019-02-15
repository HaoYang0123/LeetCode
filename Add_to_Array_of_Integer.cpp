//Leetcode 989

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int n=A.size();
		int i=n-1;
		int jw = 0;
		vector<int> res;
		while(K>0||i>=0) {
			int bit = K%10;
			K /= 10;
			int A_bit = 0;
			if(i>=0) A_bit = A[i];
			--i;
			int new_bit = (A_bit + bit + jw) % 10;
			jw = (A_bit + bit + jw) / 10;
			res.push_back(new_bit);
		}
		if(jw > 0) res.push_back(jw);
		reverse(res.begin(), res.end());
		return res;
    }
};
