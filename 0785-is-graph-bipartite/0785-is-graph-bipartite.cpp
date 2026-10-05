class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();

        queue<pair<int,int>> q;

        vector<int> vis(V,-1);

        for(int i=0;i<V;i++)
        {
            if(vis[i]==-1)
            {
                q.push({i,-1});
                vis[i]=1;
            }


        while(!q.empty())
        {
            int node=q.front().first;

            int p=q.front().second;

            q.pop();

            for(auto it:graph[node])
            {
                if(vis[it]==-1)
                {
                    if(vis[node]==1) vis[it]=0;

                    else vis[it]=1;

                    q.push({it,node});
                }
                else
                {
                    if(vis[it]==vis[node]) return false;
                }
            }
        }
        }

        return true;

    }


        
};