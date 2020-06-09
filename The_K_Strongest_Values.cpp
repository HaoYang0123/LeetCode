//Leetcode 1471

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> res(k, 0);
        int left = 0, right = arr.size()-1;
        int median = arr[(arr.size()-1)/2];
        for(int i=0;i<k;++i) {
            if(median-arr[left] > arr[right]-median) {
                res[i] = arr[left];
                ++left;
            }
            else {
                res[i] = arr[right];
                --right;
            }
        }
        return res;
    }
};
