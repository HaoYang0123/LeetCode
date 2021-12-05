// Leetcode 2087
//刚才用了df+dfs，出现runtime error，原因是stack overflow
//这题不需要用dfs，找一下规律，从(si,sj)走到(ei,ej)，只需要朝目标方向走即可，因为如果走反方向的话，要想走到目标位置，还是得走原来的方向的（相当于绕路），cost必然比朝目标方向走要大

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int si=startPos[0], sj=startPos[1];
        int ei=homePos[0], ej=homePos[1];
        int res = 0;
        if(si<=ei) {
            for(int i=si+1;i<=ei;++i) res += rowCosts[i];
        }
        else {
            for(int i=si-1;i>=ei;--i) res += rowCosts[i];
        }
        if(sj<=ej) {
            for(int i=sj+1;i<=ej;++i) res += colCosts[i];
        }
        else {
            for(int i=sj-1;i>=ej;--i) res += colCosts[i];
        }
        return res;
    }
};
