class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();

        vector<int> vis(V,-1);

        queue<pair<int,int>> q;


        for(int i=0;i<V;i++)
        {
            if(vis[i]==-1)
            {
                q.push({i,0});
                vis[i]=0;
            }

            while(!q.empty())
            {
                int node=q.front().first;
                int clr=q.front().second;
                q.pop();

                for(auto it: graph[node])
                {
                    if(vis[it]==-1)
                    {
                        if(vis[node]==0)
                        {
                            vis[it]=1;
                        }
                        else vis[it]=0;

                        q.push({it,vis[it]});
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