//Leetcode 1276
//二分查找，枚举Jumbo Burger的数量（start=0,end=tomatoSlices/4），考虑到cheeseSlices可能比较小，所以end从tomatoSlices/4和cheeseSlices中选择较小的
//然后二分查找mid，如果剩余的tomatoSlices比剩余的cheeseSlices的2倍还多，说明mid数量不够多，即start=mid+1
//如果比2倍少，则说明mid数量太多了，即end=mid-1
//如果正好是2倍，则mid是Jumbo Burger的数量，剩余的cheeseSlices为Small Burger的数量

class Solution {
public:
	vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
		int start = 0, end = tomatoSlices/4;
		end = min(end, cheeseSlices);
		while(start<=end) {
			int mid = start+(end-start)/2;
			int remaing_t = tomatoSlices - mid * 4;
			int remaing_c = cheeseSlices - mid;
			if(remaing_t > 2*remaing_c) start = mid+1;
			else if(remaing_t < 2*remaing_c) end = mid-1;
			else {
				vector<int> res(2,0);
				res[0] = mid; res[1] = remaing_c;
				return res;
			}
		}
		return vector<int>();
	}
};
