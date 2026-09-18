class Solution {
public:

    void dfs(int r, int c, vector<vector<int>> &image,
             int clr, int original, int n, int m)
    {
        image[r][c] = clr;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nc < 0 || nr >= n || nc >= m)
                continue;

            if(image[nr][nc] != original)
                continue;

            dfs(nr, nc, image, clr, original, n, m);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr, int sc, int color)
    {
        if(image.empty())
            return image;

        int n = image.size();
        int m = image[0].size();

        int original = image[sr][sc];

        // If both colors are same, nothing to do
        if(original == color)
            return image;

        dfs(sr, sc, image, color, original, n, m);

        return image;
    }
};