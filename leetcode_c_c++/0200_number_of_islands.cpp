class Solution {
public:
    void markVisitedIsland(vector<vector<char>>& grid, int r, int c) {
        if (r<0 || r>=grid.size() || c<0 || c>=grid[r].size() || grid[r][c]!='1')  return;

        int ds[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        grid[r][c] = '2';
        for (int i=0; i<4; i++) {
            markVisitedIsland(grid, r+ds[i][0], c+ds[i][1]);
        }
    } 

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;

        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if (grid[i][j]=='1') {
                    res++;
                    markVisitedIsland(grid, i, j);
                }
            }
        }
        return res;
    }
};