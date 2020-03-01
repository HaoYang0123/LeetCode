//Leetcode 1352

class ProductOfNumbers {
public:
    vector<int> nums;
    ProductOfNumbers() {
        nums.push_back(1);
    }
    
    void add(int num) {
        if(num != 0) {
            nums.push_back(nums.back()*num);
        }
        else { //如果是0，则将所有数据清空
            nums.clear();
            nums.push_back(1);
        }
    }
    
    int getProduct(int k) {
        if(k>=nums.size()) return 0; //如果k比nums数量多，证明之前有0插入，所以最近k个数相乘，包括0，则返回0
        return nums.back()/nums[nums.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
