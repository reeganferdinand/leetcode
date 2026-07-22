class Solution {
public:
    

    void dfs(int src,vector<vector<int>>& adj,vector<int> &vis,vector<int>& nums,int n)
    {
        vis[src]=1;
        nums.push_back(src);

        for(int i=0;i<n;i++)
        {
            if(adj[src][i]==1 && !vis[i])
            {
                dfs(i,adj,vis,nums,n);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> ans;
        int n=isConnected.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            vector<int> nums;
            if(!vis[i])
            {
                dfs(i,isConnected,vis,nums,n);
                ans.push_back(nums);
            }
        }

        return ans.size();
    }
};