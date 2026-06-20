class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
            }
        }
        vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int time = 0;
        while(!q.empty()){
            auto it = q.front();
            time = it.second;
            q.pop();
            for(auto [dr, dc] : d){
                int newr = it.first.first + dr;
                int newc = it.first.second + dc;
                if(newr >=0 && newr < m && newc >=0 && newc < n && grid[newr][newc] == 1){
                    grid[newr][newc] = 2;
                    q.push({{newr, newc}, time+1});
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};