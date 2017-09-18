//一个数组，元素是整数（有正、有负，或者0）
//从左到右，从右到左相乘，遇到0则置为1，表示前面的结果舍去如果没遇到0，则最大结果必然是从最左端或者最右端开始相乘得到的

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int frontProduct = 1;
    	int backProduct = 1;
  		int ans = INT_MIN;
  		for (int i = 0; i < nums.size(); ++i) {
  			frontProduct *= nums[i];
  			backProduct *= nums[nums.size() - i - 1];
  			ans = max(ans,max(frontProduct,backProduct));
  		    frontProduct = frontProduct == 0 ? 1 : frontProduct;
  		    backProduct = backProduct == 0 ? 1 : backProduct;
        }
        return ans;
    }
};
