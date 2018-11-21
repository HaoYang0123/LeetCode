//Leetcode 923
//计算3个元素和等于target的组合数目

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        unordered_map<int,int> mm; //存储每个value对应的个数
		vector<int> unique_A;
		for(int i=0;i<A.size();++i) {
			int v = A[i];
			if(mm.find(v) != mm.end()) {
				++mm[v];
			}
			else {
				mm[v] = 1;
				unique_A.push_back(v);
			}
		}
		sort(unique_A.begin(), unique_A.end());
		int res = 0;
		int MOD = 1000000007;
		for(int i=0;i<unique_A.size();++i) {
			int a=unique_A[i];
			for(int j=i;j<unique_A.size();++j) { //a<=b<=c
				int b=unique_A[j];
				int c=target-a-b;
				if(c<b) continue;
				if(mm.find(c) == mm.end()) continue;
				if(a==b && a==c && mm[a] >= 3) { //a==b==c
					long long count = (long long)mm[a];
                    //cout<<count<<endl;
					count = (count*(count-1)*(count-2))/6;
					res += (int)(count % MOD);
					res %= MOD;
				}
				else if(a==b && a < c && mm[a] >= 2) { //a==b<c
					long long count = mm[a], count2 = mm[c];
					count = count2 * ((count*(count-1))/2);
					res += (int)(count % MOD);
					res %= MOD;
				}
				else if(a<b && b==c && mm[b] >= 2) { //a<b==c
					long long count = mm[a], count2 = mm[b];
					count = count * ((count2*(count2-1))/2);
					res += (int)(count % MOD);
					res %= MOD;
				}
				else if (a<b && b<c) { //a<b<c
					long long count = mm[a], count2 = mm[b], count3 = mm[c];
					count = (count * count2 * count3);
					res += (int)(count % MOD);
					res %= MOD;
				}
			}
		}
		return res;
    }
};
