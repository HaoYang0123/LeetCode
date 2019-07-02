//Leetcode 1095
//使用二分查找，先找到mountain的peak
//从0-peak，是升序，同样二分查找target
//从peak-(n-1)，是降序，同样二分查找target
//注意二分查找找peak和找target的区别，l<r表示当前[l,r]的数目有2个，所以m和m+1必然在区间内，同时当v1<v2时，更新peak

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int l=0,r=n-1,peak=0;
        while(l<r) {
            int m=(l+r)/2;
            int v1=mountainArr.get(m);
            int v2=mountainArr.get(m+1);
            if(v1<v2) l=peak=m+1;
            else r=m;
        }
        //cout<<peak<<endl;
        l=0;
        r=peak;
        while(l<=r) {
            int m=(l+r)/2;
            if(mountainArr.get(m)<target) l=m+1;
            else if(mountainArr.get(m)>target) r=m-1;
            else return m;
        }
        l=peak;
        r=n-1;
        while(l<=r) {
            int m=(l+r)/2;
            if(mountainArr.get(m)<target) r=m-1;
            else if(mountainArr.get(m)>target) l=m+1;
            else return m;
        }
        return -1;
    }
};
