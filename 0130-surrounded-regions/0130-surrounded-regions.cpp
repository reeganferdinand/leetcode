class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));

        vector<vector<bool>> can(n,vector<bool>(m,true));

        // Top row
for (int j = 0; j < m; j++)
{
    if (board[0][j] == 'O' && !vis[0][j])
    {
        q.push({0, j});
        vis[0][j] = 1;
        can[0][j] = false;
    }
}

// Bottom row
for (int j = 0; j < m; j++)
{
    if (board[n - 1][j] == 'O' && !vis[n - 1][j])
    {
        q.push({n - 1, j});
        vis[n - 1][j] = 1;
        can[n - 1][j] = false;
    }
}

// Left column
for (int i = 1; i < n - 1; i++)
{
    if (board[i][0] == 'O' && !vis[i][0])
    {
        q.push({i, 0});
        vis[i][0] = 1;
        can[i][0] = false;
    }
}

// Right column
for (int i = 1; i < n - 1; i++)
{
    if (board[i][m - 1] == 'O' && !vis[i][m - 1])
    {
        q.push({i, m - 1});
        vis[i][m - 1] = 1;
        can[i][m - 1] = false;
    }
}
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!q.empty())
        {
            auto it=q.front();
            q.pop();

            int r=it.first;
            int c=it.second;

            for(int i=0;i<4;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='O' && !vis[nr][nc])
                {
                    vis[nr][nc]=1;
                    can[nr][nc]=false;
                    q.push({nr,nc});
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && can[i][j])
                {
                    board[i][j]='X';
                }
            }
        }
    }
};