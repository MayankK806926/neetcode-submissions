class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1) cnt++;
            }
        }
        if(q.empty() && cnt == 0) return 0;
        int time = -1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k=0;k<4;++k){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x < n && y < m && x>=0 && y>=0 && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x,y});
                    }
                }
            }
            time++;
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] == 1) return -1;
            }
        }

        return time;
    }
};
