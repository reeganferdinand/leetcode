class Solution {
public:
    
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis , vector<int>&pathVis)
    {
        vis[node]=1;
        pathVis[node]=1;

        for(auto it: adj[node])
        {
            if(pathVis[it]==1)
            {
                return true;
            }

            if(vis[it]==0 && pathVis[it]==0)
            {
                if(dfs(it,adj,vis,pathVis)==true)
                    return true;
            }
        }

        pathVis[node]=0;

        return false;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int V=numCourses;

        vector<vector<int>> adj(V);
        
        for(int i=0;i<prerequisites.size();i++)
        {
            int cr=prerequisites[i][0];
            int pr=prerequisites[i][1];

            adj[pr].push_back(cr);
        }


        vector<int> vis(V,0);

        vector<int> pathVis(V,0);

        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,pathVis)==true)
                {
                    return false;
                }
            }
        }


        return true;
        
    }
};