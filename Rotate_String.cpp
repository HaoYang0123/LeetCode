//Leetcode 796
//判断A+A是否包含B，且A和B的长度是否一致。

class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.length() != B.length()) return false;
        string A2 = A+A;
        //cout<<A2<<"\t"<<B<<endl;
        //cout<<A2.find(B)<<endl;
        int ind = (int)A2.find(B);
        return (ind >= 0);
    }
};
