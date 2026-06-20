class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int &v_count, int &e_count){
        vis[node] = 1;
        v_count++;
        e_count += adj[node].size();
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, v_count, e_count);
            }
        }
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        vector<int> vis(n, 0);
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                int v_count = 0;
                int e_count = 0;
                dfs(i, adj, vis, v_count, e_count);
                if(e_count == v_count * (v_count - 1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};