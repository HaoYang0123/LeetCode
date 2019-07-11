//Leetcode 1109

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(20002, 0);
        int min_ind = INT_MAX, max_ind = INT_MIN;
        for(int i=0;i<bookings.size();++i) { //从X至Y有Z(X=bookings[i][2])个乘客
            res[bookings[i][0]] += bookings[i][2]; //相当于从X上了Z个乘客
            res[bookings[i][1]+1] -= bookings[i][2]; //从Y+1下了Z个乘客
            if(bookings[i][0] < min_ind) min_ind = bookings[i][0];
            if(bookings[i][1] > max_ind) max_ind = bookings[i][1];
        }
        vector<int> res2(n, 0);
        for(int i=1;i<=max_ind;++i) { //整个乘客数量等于res的前缀和
            res[i] += res[i-1];
            res2[i-1] = res[i];
        }
        return res2;
    }
};
