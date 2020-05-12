//Leetocde 1442
//枚举(i,j)的xor，只要等于0，那么就会形成(j-i)个结果
//比如：数组[2,3,1,6,7]
//会出现[2,3,1]的xor为0，那么就有两个结果：(2, [3,1])和([[2,3], 1)
//同样[1,6,7]的xor为0，那么也有两个结果

class Solution {
public:
	int countTriplets(vector<int> & arr) {
		int n = arr.size();
		int res = 0;
		for (int i = 0; i < n; ++i) {
			int cur = arr[i];
			for (int j = i + 1; j < n; ++j) {
				cur = cur ^ arr[j];
				if (cur == 0) res += (j - i);
			}
		}
		return res;
	}
};
