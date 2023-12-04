class Solution {
public:
    int getSize(int x, int y, vector<vector<int>>& grid){
        if(x<0 || y<0 || x>=grid[0].size() || y>=grid.size()){
            return 0;
        }
        if(grid[y][x] == 0){
            return 0;
        }
        grid[y][x] = 0;
        int surrounding = getSize(x+1, y, grid) + getSize(x-1, y, grid) + getSize(x, y+1, grid) + getSize(x, y-1, grid);
        return 1 + surrounding;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSize = 0;
        for(int y = 0; y<grid.size(); y++){
            for(int x = 0; x<grid[0].size(); x++){
                if(grid[y][x] == 1){
                    maxSize = max(maxSize, getSize(x, y, grid)); 
                }
            }
        }
        return maxSize;
    }
};


