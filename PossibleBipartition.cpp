//Leetcode 886
//二分图分割，有N个人，分成两个组织，有些人不喜欢另一些人，他们不能在同一个组织中。

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> map(N+1,0); //N个人的桶，map[i]=1表示第i个人在组织1中，=2表示在组织2中。
        vector<vector<int>> edges(N+1,vector<int>());
        for(int i=0;i<dislikes.size();++i) {
            edges[dislikes[i][0]].push_back(dislikes[i][1]);
            edges[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        map[1]=1;
        vector<int> floor;
        floor.push_back(1);
        int flag = 2;
        while(floor.size()>0) {
            //cout<<floor.size()<<"\t"<<flag<<endl;
            //for(int i=0;i<floor.size();++i) cout<<floor[i]<<endl;
            //cout<<"-------"<<endl;
            //for(int i=1;i<=N;++i) cout<<map[i]<<" ";
            //cout<<"-------"<<endl;
            vector<int> newFloor;
            for(int i=0;i<floor.size();++i) {
                vector<int> edge = edges[floor[i]];
                for(int j=0;j<edge.size();++j) {
                    if(map[edge[j]] != 0 && map[edge[j]] != flag) return false; //如果不在想要的组织，则说明有冲突，返回false即可
                    if(map[edge[j]] == 0) {
                        map[edge[j]] = flag;
                        newFloor.push_back(edge[j]);
                    }
                }
            }
            floor = newFloor;
            if(floor.size()==0) { //必须有此判断，因为图是多个连通图，处理完其中一个后，需要处理其它连通图。
                for(int i=1;i<=N;++i) {
                    if(map[i] == 0) {
                        floor.push_back(i);
                        map[i]=flag;
                        break;
                    }
                }
            }
            flag = (flag == 1 ? 2 : 1);
        }
        return true;
    }
};
