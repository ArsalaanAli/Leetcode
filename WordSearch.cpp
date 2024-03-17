class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(searchWord(i, j, 0, board, word)){
                    return true;
                }
            }
        }
        return false;
    }
    bool searchWord(int y, int x, int cur, vector<vector<char>>& board, string word){
        if(y < 0 || y >= board.size() || x < 0 || x >= board[0].size() || word[cur] != board[y][x]){
            return false;
        }
        if(cur == word.size()-1){
            return true;
        }
        board[y][x] = '.';
        if (searchWord(y+1, x, cur+1, board, word) || searchWord(y-1, x, cur+1, board, word) || searchWord(y, x+1, cur+1, board, word) || searchWord(y, x-1, cur+1, board, word)){
            return true;
        }
        board[y][x] = word[cur];
        return false;
    }
};
