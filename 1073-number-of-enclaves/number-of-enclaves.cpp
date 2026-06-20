class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1){
                    if (grid[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto [dx, dy] : direction){
                int nx = x+dx;
                int ny = y+dy;
                if(nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny] == 0 && grid[nx][ny] == 1){
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                    grid[nx][ny] = 0;
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i>0 && i<m-1 && j>0 && j<n-1){
                    if(grid[i][j] == 1) cnt++;
                }
            }
        }
        return cnt;

    }
};