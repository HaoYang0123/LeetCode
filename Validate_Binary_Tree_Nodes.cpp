//Leetcode 1361
//统计各结点的入度，如果是树的话，需要同时满足两个条件：1）所有结点的入度不超过1；2）有且仅有一个结点的入度为0（即根结点）

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> in_degree(n, 0);
        for(int i=0;i<n;++i) {
            if(leftChild[i] != -1) in_degree[leftChild[i]]++;
            if(rightChild[i] != -1) in_degree[rightChild[i]]++;
        }
        int zero_num = 0;
        //for(int i=0;i<n;++i) cout<<i<<"\t"<<in_degree[i]<<endl;
        for(int i=0;i<n;++i) {
            if(in_degree[i] > 1) return false;
            if(in_degree[i] == 0) ++zero_num;
        }
        return (zero_num == 1);
    }
};
