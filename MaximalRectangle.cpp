class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> right(m, vector<int>(n, 0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] == '1'){
                    right[i][j] = 1;
                    if(j>0){
                        right[i][j] += right[i][j-1];
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(right[i][j]){
                    int y = i;
                    int width = right[i][j];
                    int tot = 0;
                    while(y<m && right[y][j]){
                        width = min(width, right[y][j]);
                        tot = width * (y-i+1);
                        ans = max(ans, tot);
                        y++;
                    }
                }
            }
        }
        return ans;
    }
};

