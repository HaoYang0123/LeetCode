//Leetcode 4
//方法1：时间复杂度为O(N+M)非O(log(N+M))

//方法1：使用两个指针，如果nums1[i]<nums2[j]，那么++i；否则++j，直到i+j找到median对应的位置
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        int total = n+m;
        int first = (total % 2 ? total/2 : total/2-1);
        int second = (total % 2 ? first : first + 1);
        //cout<<first<<"\t"<<second<<endl;
        int i=0,j=0;
        int first_val = 0, second_val = 0;
        while(true) {
            int i_val = (i<n ? nums1[i] : INT_MAX);
            int j_val = (j<m ? nums2[j] : INT_MAX);
            if(i+j == first) first_val = (i_val < j_val ? i_val : j_val);
            if(i+j == second) {
                second_val = (i_val < j_val ? i_val : j_val);
                break;
            }
            if(i_val < j_val) ++i;
            else ++j;
        }
        return (first_val + second_val) * 1.0 / 2;
    }
};
