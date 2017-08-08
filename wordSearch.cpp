class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.length() == 0) return true;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(board[i][j] != word[0]) continue;
                visited[i][j] = true;
                if(exist(board, i, j, visited, word, 1)) return true;
                visited[i][j] = false;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>> & board, int r, int c, vector<vector<bool>> & visited, string & word, int wPos) {
        if(wPos >= word.length()) return true;
        
        int rStep[4] = {-1, 1, 0, 0};
        int cStep[4] = {0, 0, -1, 1};
        
        for(int i = 0; i < 4; ++i) {
            int newR = r + rStep[i], newC = c + cStep[i];
            if(newR < 0 || newR >= board.size()) continue;
            if(newC < 0 || newC >= board[0].size()) continue;
            if(visited[newR][newC]) continue;
            if(board[newR][newC] != word[wPos]) continue;
            visited[newR][newC] = true;
            if(exist(board, newR, newC, visited, word, wPos + 1)) {
                //visited[newR][newC] = false;
                return true;
            }
            visited[newR][newC] = false;
        }
        
        return false;
    }
};