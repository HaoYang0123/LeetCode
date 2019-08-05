//Leetcode 1144
//之前看错题目了，以为num可以+1，也可以-1，原来只允许-1的情况。
//所以如果即可以+1，又可以-1，问题会更加难，写的代码可以参见方法2

//方法1：与题目问题一致，只考虑-1的情况
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
      int r1 = 0, r2 = 0;
      int flag = 0; //0表示向上，1表示向下
      int n = nums.size();
        vector<int> old_nums = nums;
        for(int i=0;i<n-1;++i) {
            if(flag==0) {
                if(nums[i]>=nums[i+1]) {
                    r1 += (nums[i]+1-nums[i+1]);
                    nums[i]=nums[i+1]-1;
                }
                flag = 1;
            }
            else {
                if(nums[i]<=nums[i+1]) {
                    r1 += (nums[i+1]+1-nums[i]);
                    nums[i+1] = nums[i]-1;
                }
                flag = 0;
            }
        }
        nums = old_nums;
        flag = 1;
        for(int i=0;i<n-1;++i) {
            if(flag==0) {
                if(nums[i]>=nums[i+1]) {
                    r2 += (nums[i]+1-nums[i+1]);
                    nums[i]=nums[i+1]-1;
                }
                flag = 1;
            }
            else {
                if(nums[i]<=nums[i+1]) {
                    r2 += (nums[i+1]+1-nums[i]);
                    nums[i+1] = nums[i]-1;
                }
                flag = 0;
            }
        }
        return min(r1, r2);
    }
};

//方法2：即可以+1，又可以-1
class Solution {
public:
	int movesToMakeZigzag(vector<int>& nums) {
		int r1 = 0, r2 = 0;
		int flag = 0; //0表示向上，1表示向下
		int n = nums.size();
        vector<int> old_nums = nums;
		for (int i = 0; i < n - 1; ++i) {
			if (flag == 0) {
				if (nums[i] >= nums[i + 1]) {
					r1 += (nums[i] + 1 - nums[i + 1]);
					if(i+2<n) {
						if(nums[i+2]>=nums[i+1]) {
							int new_t = (nums[i+2]+1-nums[i+1]);
							int new_i1 = nums[i]+1;
							int new_t2 = 0;
							if(nums[i+2] >= new_i1) new_t2 = (nums[i+2]+1-new_i1);
							if(new_t2 < new_t) {
								nums[i+1]=new_i1;
							}
						}
					}
				}
				flag = 1;
			}
			else {
				if (nums[i] <= nums[i + 1]) {
					r1 += (nums[i + 1] + 1 - nums[i]);
					if(i+2<n) {
						if(nums[i+2] <= nums[i+1]) {
							int new_t = (nums[i+1]+1-nums[i+2]);
							int new_i1 = nums[i] - 1;
							int new_t2 = 0;
							if(nums[i+2]<=new_i1) new_t2 = (new_i1+1-nums[i+2]);
							if(new_t2 < new_t) {
								nums[i+1] = new_i1;
							}
						}
					}
				}
				flag = 0;
			}
		}
		flag = 1;
        nums = old_nums;
		for (int i = 0; i < n - 1; ++i) {
			if (flag == 0) {
				if (nums[i] >= nums[i + 1]) {
					r2 += (nums[i] + 1 - nums[i + 1]);
					if(i+2<n) {
						if(nums[i+2]>=nums[i+1]) {
							int new_t = (nums[i+2]+1-nums[i+1]);
							int new_i1 = nums[i]+1;
							int new_t2 = 0;
							if(nums[i+2] >= new_i1) new_t2 = (nums[i+2]+1-new_i1);
							if(new_t2 < new_t) {
								nums[i+1]=new_i1;
							}
						}
					}
				}
				flag = 1;
			}
			else {
				if (nums[i] <= nums[i + 1]) {
					r2 += (nums[i + 1] + 1 - nums[i]);
					if(i+2<n) {
						if(nums[i+2] <= nums[i+1]) {
							int new_t = (nums[i+1]+1-nums[i+2]);
							int new_i1 = nums[i] - 1;
							int new_t2 = 0;
							if(nums[i+2]<=new_i1) new_t2 = (new_i1+1-nums[i+2]);
							if(new_t2 < new_t) {
								nums[i+1] = new_i1;
							}
						}
					}
				}
				flag = 0;
			}
		}
        cout<<r1<<"\t"<<r2<<endl;
		return min(r1, r2);
	}
};
