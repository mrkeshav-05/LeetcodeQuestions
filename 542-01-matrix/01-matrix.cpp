class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // dist matrix to store results, initialized with -1 (meaning unvisited)
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        
        // Step 1: Push all 0s into the queue
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        // Step 2: Multi-source BFS
        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int newr = row + dr[i];
                int newc = col + dc[i];
                
                // If neighbor is within bounds and unvisited (dist == -1)
                if(newr >= 0 && newr < m && newc >= 0 && newc < n && dist[newr][newc] == -1){
                    dist[newr][newc] = dist[row][col] + 1;
                    q.push({newr, newc});
                }
            }
        }
        return dist;
    }
};