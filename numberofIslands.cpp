class Solution {
public:
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        int count = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (!visited[i][j] && grid[i][j]=='1'){
                    dfs(grid,visited,i,j);
                    count++;
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        int m = grid.size(), n=grid[0].size();
        if (x<0||x>=m||y<0||y>=n||visited[x][y]||grid[x][y]=='0') return;
        visited[x][y] = true;
        dfs(grid,visited,x-1,y);
        dfs(grid,visited,x+1,y);
        dfs(grid,visited,x,y-1);
        dfs(grid,visited,x,y+1);
    }
};