// Leetcode 733
// BFS

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size();
        if(image[sr][sc] == newColor) return image;
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        queue<pair<int,int>> qs;
        qs.push({sr, sc});
        int r_step[] = {0,0,-1,1};
        int c_step[] = {-1,1,0,0};
        while(!qs.empty()) {
            pair<int,int> cur = qs.front();
            int cx = cur.first, cy = cur.second;
            qs.pop();
            for(int i=0;i<4;++i) {
                int nx = cx + r_step[i];
                int ny = cy + c_step[i];
                if(nx < 0 || nx >= m) continue;
                if(ny < 0 || ny >= n) continue;
                if(image[nx][ny] == oldColor) {
                    image[nx][ny] = newColor;
                    qs.push({nx, ny});
                }
            }
        }
        return image;
    }
};
