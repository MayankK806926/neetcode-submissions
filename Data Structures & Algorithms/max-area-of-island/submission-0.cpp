class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){
        vis[i][j] = 1;
        int cnt = 1;
        for(int k=0;k<4;++k){
            int x = i + dx[k];
            int y = j + dy[k];
            if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1 && !vis[x][y]){
                cnt += dfs(x,y,grid,vis);
            }
        }
        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] == 1 && !vis[i][j]){
                    ans = max(ans,dfs(i,j,grid,vis));
                }
            }
        }

        return ans;
    }
};
