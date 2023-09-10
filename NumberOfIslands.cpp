class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int y = 0; y<grid.size(); y++){
            for(int x = 0; x<grid[0].size(); x++){
                if(grid[y][x] == '1'){
                    ans++;
                    visitIslands(x, y, grid);
                }
            }
        }
        return ans;
    }
    void visitIslands(int x, int y, vector<vector<char>>& grid){
        if( x < 0 || y < 0 || x >= grid[0].size() || y >= grid.size() || grid[y][x] == '0' ){
            return;
        }
        grid[y][x] = '0';
        visitIslands(x-1, y, grid);
        visitIslands(x+1, y, grid);
        visitIslands(x, y-1, grid);
        visitIslands(x, y+1, grid);
    }
};
