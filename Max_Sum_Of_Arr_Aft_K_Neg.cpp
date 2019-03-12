//Leetcode 1005
//O(N)的时间复杂度

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int zero_num = 0;
		int neg_num = 0;
		int pos_sum = 0;
		vector<int> negs;
		for(int i=0;i<A.size();++i) {
			if(A[i]==0) ++zero_num;
			else if(A[i]<0) {
				negs.push_back(A[i]);
				++neg_num;
			}
			else pos_sum += A[i];
		}
		if(K>=neg_num) {
			if((K-neg_num)%2==0) { //如果多余的置换，是偶数，那么可以置换某个值偶数次仍然是正数
				int res = pos_sum;
				for(int i=0;i<negs.size();++i) res += -negs[i];
				return res;
			}
			else { //如果多余的置换是奇数，那么分两种情况。如果有负数，则不加最大的负数；如果没有，则减去最小的正数
				if (zero_num>0) { //如果有0元素，那么直接将所有负数置换成正数，多余的置换给0
					int res = pos_sum;
					for(int i=0;i<negs.size();++i) res += -negs[i];
					return res;
				}
				else if(neg_num == 0) {
					int min=INT_MAX;
					for(int i=0;i<A.size();++i) {
						if(A[i]<min) min=A[i];
					}
					return pos_sum - 2*min;
				}
				else {
					int max = INT_MIN,min = INT_MAX;
					int res = pos_sum;
					for(int i=0;i<negs.size();++i) {
						if(negs[i]>max) max=negs[i];
						res += -negs[i];
					}
					for(int i=0;i<A.size();++i) {
						if(A[i]>0 && A[i]<min) min=A[i];
					}
					int res1 = res + 2*max, res2 = res - 2*min;
					return (res1>res2 ? res1 : res2);
				}
			}
		}
		else { //负数非常多，多于置换的数目，那么置换最小K个负数
			sort(negs.begin(), negs.end());
			int res = pos_sum;
			for(int i=0;i<negs.size();++i) {
				if(i<K) res += -negs[i];
				else res += negs[i];
			}
			return res;
		}
    }
};
