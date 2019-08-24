//Leetcode 1007

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int a = A[0];
        int b = B[0];
        int n=A.size();
        //cout<<n<<endl;
        unordered_map<int, bool> mm;
        unordered_map<int, int> num1, num2;
        mm[a] = true;
        mm[b] = true;
        num1[a] = 1;
        num2[b] = 1;
        for(int i=1;i<n;++i) {
            if(A[i] != a && B[i] != a) mm[a] = false;
            if(A[i] != b && B[i] != b) mm[b] = false;
            if(mm[a] == false && mm[b] == false) return -1;
            num1[A[i]]++;
            num2[B[i]]++;
        }
        
        int res = INT_MAX;
        for(auto ind = mm.begin();ind != mm.end(); ++ind) {
            if(!ind->second) continue;
            int v = ind->first;
            //cout<<v<<endl;
            res = min(res, min(n-num1[v], n-num2[v]));
        }
        return res;
    }
};
