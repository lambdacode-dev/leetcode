class Solution {
    //[dfs]
    //(time, space) = O(N) O(N)
    public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid.front().size();
        
        function<void(int, int)> dfs;
        dfs = [&dfs, &grid, &rows, &cols](int r, int c) {
            grid[r][c] = '0'; // mark visited.
            
            if(r > 0 && grid[r-1][c] == '1')        dfs(r-1, c);
            if(c > 0 && grid[r][c-1] == '1')        dfs(r, c-1);
            if(r < rows-1 && grid[r+1][c] == '1')   dfs(r+1, c);
            if(c < cols-1 && grid[r][c+1] == '1')   dfs(r, c+1);
        };
        
        int islands = 0;
        for(int r = rows - 1; r >= 0; --r) {
            for(int c = cols - 1; c >= 0; --c) {
                if(grid[r][c] == '1') {
                    islands++;
                    dfs(r,c);
                }
            }
        }
        return islands;
    }
};
