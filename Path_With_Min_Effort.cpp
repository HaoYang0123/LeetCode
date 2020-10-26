//Leetcode 1631
//Dijstra算法


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        vector<vector<int>> distance(row, vector<int>(col, INT_MAX));
        
        vector<int> dirX = {0, 0,-1, 1};
        vector<int> dirY = {-1, 1, 0, 0};
        
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> st;
        st.push(pair<int,pair<int,int>>(0,pair<int,int>(0,0)));
        
        while (!st.empty()) 
        { 
            pair<int, pair<int,int>> cur = st.top();
            st.pop(); 
            int curX = cur.second.first;
            int curY = cur.second.second;
            int curS = cur.first;
            //cout<<curX<<"\t"<<curY<<"\t"<<curS<<endl;
            if(distance[curX][curY] <= curS) continue;
            distance[curX][curY] = curS;
            if(curX == row-1 && curY == col-1) return curS;
            for(int k=0;k<4;++k) {
                int newX = curX + dirX[k];
                int newY = curY + dirY[k];
                if(newX < 0 || newX >= row) continue;
                if(newY < 0 || newY >= col) continue;
                int cur_dis = max(curS, abs(heights[curX][curY] - heights[newX][newY]));
                //cout<<"NNN\t"<<newX<<"\t"<<newY<<"\t"<<cur_dis<<endl;
                st.push(pair<int,pair<int,int>>(cur_dis, pair<int,int>(newX, newY)));
            }
        }
        return distance[row - 1][col - 1];
    }
};


//方法2，也是Dijistra算法，用的网上的代码，运行速度更快

struct pos {
    int distance, x, y;
    pos(int x, int y, int distance) : x(x), y(y), distance(distance) {}
};

bool operator<(const pos& a, const pos& b) 
{ 
    if (a.distance == b.distance) 
    { 
        if (a.x != b.x) 
            return (a.x < b.x); 
        else
            return (a.y < b.y); 
    } 
    return (a.distance < b.distance); 
} 

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        vector<vector<int>> distance(row, vector<int>(col, INT_MAX));
        
        vector<int> dirX = {-1, 0, 1, 0};
        vector<int> dirY = {0, -1, 0, 1};
        
        set<pos> st;
        st.insert(pos(0, 0, 0));
        distance[0][0] = 0;
        
        while (!st.empty()) 
        { 
            pos k = *st.begin(); 
            st.erase(st.begin()); 

            for (int i = 0; i < 4; i++) 
            { 
                int x = k.x + dirX[i]; 
                int y = k.y + dirY[i]; 
                
                if(x < 0 || x >= row || y < 0 || y >= col) continue;
                int diff = max(abs(heights[x][y] - heights[k.x][k.y]), k.distance);
                if (distance[x][y] > diff) //新到达的(x,y)更好，所以需要将其进行更新
                { 
                    if (distance[x][y] != INT_MAX) 
                        st.erase(st.find(pos(x, y, distance[x][y]))); 

                    distance[x][y] = diff; 
                    st.insert(pos(x, y, distance[x][y])); 
                } 
            } 
        }
        return distance[row - 1][col - 1];
    }
};
