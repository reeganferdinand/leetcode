class Solution {
public:

    void dfs(vector<vector<int>>& adj, int node, vector<int>& vis)
    {
        vis[node] = 1;

        for(int it : adj[node])
        {
            if(!vis[it])
            {
                dfs(adj, it, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();

        vector<vector<int>> adj(n);

        // Convert adjacency matrix to adjacency list
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isConnected[i][j] == 1 && i != j)
                {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(n, 0);
        int count = 0;

        // Count connected components
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(adj, i, vis);
            }
        }

        return count;
    }
};