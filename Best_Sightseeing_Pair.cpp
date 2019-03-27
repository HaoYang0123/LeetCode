//Leetcode 1021
//第一套是我自己写的代码（贪心+剪枝，几乎超时），第二套思路比较巧妙，O(N)时间复杂度

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
		map<int, vector<int>> mm; //存储各元素对应在A中的索引位置
		int n=A.size();
		for(int i=0;i<n;++i) {
			mm[A[i]].push_back(i);
		}

		int res = 0;
		for(int i=0;i<n-1;++i) {
			int tmp = (A[i]+A[i+1]-1);
			if(tmp > res) res = tmp;
			auto ind = mm.upper_bound(A[i+1]); //找到比A[i+1]大的元素，比A[i+1]小或者相等的值肯定不如tmp大
			for(;ind != mm.end(); ++ind) {
                int tmp_max = (A[i]+ind->first-2);
				if(tmp_max <= res) continue; //减枝
				vector<int> values = ind->second;
				auto ind2 = upper_bound(values.begin(), values.end(), i+1); //在values中找索引值比i+1大的
				if(ind2 == values.end()) continue;
				int tmp2 = (A[i]+A[*ind2]-(*ind2-i));
				if(tmp2 > res) res = tmp2;
			}
		}
		return res;
    }
};

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) { //find max(A[i]+i+A[j]-j) for i<j
        int res=0,pre=A[0]; //pre记录当前最大的A[i]+i
        for(int i=1;i<A.size();++i) {
            res=max(res, pre+A[i]-i); //A[i]-i相当于上式的A[j]-j
            pre=max(pre, A[i]+i);
        }
        return res;
    }
};
