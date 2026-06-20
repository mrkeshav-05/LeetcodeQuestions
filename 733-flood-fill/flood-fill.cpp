class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        // If the target color is the same as the initial, no work is needed
        if (initialColor != color) {
            bfs(sr, sc, image, color, initialColor);
        }
        return image;
    }

    void bfs(int sr, int sc, vector<vector<int>> &image, int color, int initialColor) {
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color; // Fill starting pixel

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()){
            auto [i, j] = q.front(); // Use .front() for queue
            q.pop();

            for(int k = 0; k < 4; k++){
                int newr = i + dr[k];
                int newc = j + dc[k];

                // Check bounds and if the pixel matches the initial color
                if(newr >= 0 && newr < image.size() && newc >= 0 && newc < image[0].size() 
                   && image[newr][newc] == initialColor){
                    image[newr][newc] = color;
                    q.push({newr, newc});
                }
            }
        }
    }
};