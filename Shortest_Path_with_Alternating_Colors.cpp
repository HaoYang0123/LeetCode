//Leetcode 1129

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int>> matrixr(n,vector<int>()), matrixb(n,vector<int>());
        //更新图，matrixr(matrixb)[i]表示从i到达其它结点的索引数组，连接的边的颜色是红色（蓝色）
        for(int i=0;i<red_edges.size();++i) {
            int s=red_edges[i][0],e=red_edges[i][1];
            matrixr[s].push_back(e);
        }
        for(int i=0;i<blue_edges.size();++i) {
            int s=blue_edges[i][0],e=blue_edges[i][1];
            matrixb[s].push_back(e);
        }
        queue<pair<int,int>> qsr, qsb; //qsr(qsb)[i][j]表示从0到达i的最小步数为j，最后的边颜色是红色（蓝色）
        vector<int> res(n,INT_MAX), is_visr(n,0), is_visb(n,0); //res表示从0到达其它结点的最小步数
        //is_visr(is_visb)[i]表示是否访问过i，最后的边颜色是红色（蓝色）
        qsr.push(pair<int,int>(0,0));
        qsb.push(pair<int,int>(0,0));
        res[0]=0;
        is_visr[0] = is_visb[0] = 1;
        while(!qsr.empty()||!qsb.empty()) {
            if(!qsr.empty()) {
                pair<int,int> c=qsr.front(); //c表示到达c的颜色是红色
                qsr.pop();
                vector<int> edges = matrixb[c.first]; //edges表示从c到达的颜色为蓝色的边
                for(int i=0;i<edges.size();++i) {
                    int e=edges[i];
                    if(is_visb[e]!=0) continue;
                    is_visb[e]=1;
                    res[e]=min(res[e],c.second+1);
                    qsb.push(pair<int,int>(e,c.second+1));
                }
            }
            if(!qsb.empty()) {
                pair<int,int> c=qsb.front();
                qsb.pop();
                vector<int> edges = matrixr[c.first];
                for(int i=0;i<edges.size();++i) {
                    int e=edges[i];
                    if(is_visr[e]!=0) continue;
                    is_visr[e]=1;
                    res[e]=min(res[e],c.second+1);
                    qsr.push(pair<int,int>(e,c.second+1));
                }
            }
        }
        for(int i=1;i<n;++i) {
            if(res[i]==INT_MAX) res[i]=-1; //最后,INT_MAX表示从0到达不了i
        }
        return res;
    }
};
