// Leetcode 1685
//[x1, x2, x3, x4, x5]
//那么第1个元素为：(x2-x1)+(x3-x1)+...+(x5-x1) = (x1+x2+...+x5)-5*x1
//第2个元素为：(x2-x1)+(x3-x2)+...+(x5-x2)=2*x2-(x1+x2) + (x2+...+x5)-4*x2
//第3个元素为：(x3-x1)+(x3-x2)+...+(x5-x3)=3*x3-(x1+...+x3) + (x3+...+x5)-3*x3
//所以第i个元素可以表示为：i*xi - (x1+...+xi) + (xi+...+x5)-(6-i)*xi

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_sum(n+1, 0); // prefix_sum[i+1]表示从0至i的和
        prefix_sum[1] = nums[0];
        for(int i=1; i<n; ++i) {
            prefix_sum[i+1] = prefix_sum[i] + nums[i];
        }
        int sum = prefix_sum[n];
        //cout<<"SUM\t"<<sum<<endl;
        vector<int> res(n, 0);
        for(int i=0; i<n; ++i) {
            int right_sum = sum - prefix_sum[i];
            int left_sum = prefix_sum[i+1];
            //cout<<i<<"\t"<<left_sum<<"\t"<<right_sum<<endl;
            int val = 0;
            if(i < n) {
                val += right_sum - (n - i) * nums[i];
                //cout<<"Val\t"<<i<<"\t"<<val<<endl;
            }
            if(i > 0) {
                val += (i + 1) * nums[i] - left_sum;
                //cout<<"Val\t"<<i<<"\t"<<val<<endl;
            }
            res[i] = val;
        }
        return res;
    }
};
