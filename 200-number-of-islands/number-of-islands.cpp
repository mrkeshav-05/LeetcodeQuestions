class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[i][j] = 1;
        
        // Define only the 4 cardinal directions
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for(int k = 0; k < 4; k++){
            int row = i + dr[k];
            int col = j + dc[k];
            
            if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() 
               && !vis[row][col] && grid[row][col] == '1'){
                dfs(row, col, grid, vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i, j, grid, vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};