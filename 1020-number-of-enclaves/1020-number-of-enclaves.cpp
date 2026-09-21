class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        if(grid.empty())
            return 0;

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        // Top and bottom rows
        for(int j = 0; j < m; j++)
        {
            if(grid[0][j] == 1)
            {
                q.push({0, j});
                grid[0][j] = 0;
            }

            if(grid[n-1][j] == 1)
            {
                q.push({n-1, j});
                grid[n-1][j] = 0;
            }
        }

        // Left and right columns
        for(int i = 0; i < n; i++)
        {
            if(grid[i][0] == 1)
            {
                q.push({i, 0});
                grid[i][0] = 0;
            }

            if(grid[i][m-1] == 1)
            {
                q.push({i, m-1});
                grid[i][m-1] = 0;
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   grid[nr][nc] == 1)
                {
                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                }
            }
        }

        int count = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};