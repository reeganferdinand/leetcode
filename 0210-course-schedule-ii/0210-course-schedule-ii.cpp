class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        
    if (prerequisites.empty()) {
        vector<int> ans;
        for (int i = 0; i < numCourses; i++)
        ans.push_back(i);
        return ans;
    }
        
        
        
        vector<int> ans;
        int V=numCourses;
        vector<vector<int>> adj(V);

        vector<int> ind(V,0);

        for(int i=0;i<prerequisites.size();i++)
        {
            int cr=prerequisites[i][0];
            int pr=prerequisites[i][1];

            adj[pr].push_back(cr);

            ind[cr]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(ind[i]==0)
            {
                q.push(i);
            }
        }


        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node])
            {
                ind[it]--;

                if(ind[it]==0)
                {
                    q.push(it);
                }
            }
        }

        if(ans.size()!=V) return {};
    
        return ans;
    }
};