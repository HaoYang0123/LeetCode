//Leetcode 934
//在两维数组中，计算两个island的最小距离

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int n=A.size(),m=A[0].size();
        vector<pair<int, int>> one, two; // 记录两个islands的(x,y)坐标
        bool flag=true; //true记录第一个island，false记录第二个island
        vector<vector<bool>> is_visited(n,vector<bool>(m,0)); //记录坐标(x,y)是否被访问过
        int rstep[] = {-1,1,0,0};
        int cstep[] = {0,0,-1,1};
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(A[i][j]==0 || is_visited[i][j]) continue;
                vector<pair<int, int>> tmp;
                queue<pair<int, int>> qs; //使用宽度优先搜索来获取一个island
                is_visited[i][j] = true;
                qs.push(pair<int,int>(i,j));
                while(!qs.empty()) {
                    pair<int, int> cur = qs.front();
                    qs.pop();
                    tmp.push_back(cur);
                    for(int k=0;k<4;++k) {
                        int nx = cur.first + rstep[k];
                        int ny = cur.second + cstep[k];
                        if(nx>=0&&nx<n&&ny>=0&&ny<m&&A[nx][ny]==1&&!is_visited[nx][ny]) {
                            is_visited[nx][ny] = true;
                            qs.push(pair<int,int>(nx,ny));
                        }
                    }
                }
                if(flag) {
                    flag = false;
                    one = tmp;
                }
                else two = tmp;
            }
        }
        int res = INT_MAX;
        for(int i=0;i<one.size();++i) {
            int one_x = one[i].first, one_y = one[i].second;
            for(int j=0;j<two.size();++j) {
                int two_x = two[j].first, two_y = two[j].second;
                int tmp = abs(one_x - two_x) + abs(one_y - two_y);
                //cout<<one_x<<"\t"<<one_y<<"\t"<<two_x<<"\t"<<two_y<<"\t"<<tmp<<endl;
                if(tmp < res) res = tmp;
            }
        }
        //cout<<one.size()<<"\t"<<two.size()<<endl;
        return res - 1;
    }
};
