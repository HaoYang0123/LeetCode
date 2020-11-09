//Leetcode 1640

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int v = 0;
        for(int i=0;i<arr.size();++i) {
            //cout<<"I\t"<<i<<"\t"<<arr[i]<<endl;
            int idx = find_pie(arr[i], pieces);
            if(idx == -1) return false;
            vector<int> & pie = pieces[idx];
            int j=i+1;
            for(;j<arr.size()&&j-i<pie.size();++j) {
                if(pie[j-i] != arr[j]) return false;
            }
            //cout<<"J\t"<<j<<endl;
            if(j-i<pie.size()) return false;
            i = j-1;
            ++v;
        }
        //cout<<v<<endl;
        return (v==pieces.size());
    }
    
    inline int find_pie(int v, vector<vector<int>> & pieces) {
        for(int i=0;i<pieces.size();++i) {
            if(v == pieces[i][0]) return i;
        }
        return -1;
    }
};
