class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> rotten;
        int fresh =0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    rotten.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        int ans=0;
        while(!rotten.empty())
        {
            int size=rotten.size();
            bool changed=false;
            for(int i=0;i<size;i++)
            {
                auto it=rotten.front();
                rotten.pop();

                for(int i=0;i<4;i++)
                {
                    int r=it.first+dr[i];
                    int c=it.second+dc[i];

                    if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1)
                    {
                        rotten.push({r,c});
                        grid[r][c]=2;
                        fresh--;
                        changed=true;
                    }                   
                }
            }

            if(changed) ans++;
        }

        if(fresh==0)
        {
            return ans;
        }
        
        return -1;
    }
};