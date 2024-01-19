class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int y = 1; y<n; y++){
            for(int x = 0; x<n; x++){
                if(x == 0){
                    matrix[y][x] = min(matrix[y][x]+matrix[y-1][x],matrix[y][x]+matrix[y-1][x+1]);
                }
                else if(x == n-1){
                    matrix[y][x] = min(matrix[y][x]+matrix[y-1][x],matrix[y][x]+matrix[y-1][x-1]);
                }
                else{
                    matrix[y][x] = min({matrix[y][x]+matrix[y-1][x], matrix[y][x]+matrix[y-1][x+1], matrix[y][x]+matrix[y-1][x-1]});
                }
            }
        }
        return *min_element(matrix[n-1].begin(), matrix[n-1].end());
    }  
};