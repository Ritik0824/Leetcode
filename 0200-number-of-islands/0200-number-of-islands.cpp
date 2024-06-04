class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {-1,0,1,0};

    void bfs(int x,int y,vector<vector<char>>& grid,int n, int m){
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[x][y]=1;
        queue<pair<int,int>> q;
        q.push(make_pair(x,y));
        grid[x][y] = '0';
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0){
                    if(grid[nrow][ncol] == '1'){
                        q.push(make_pair(nrow,ncol));
                        vis[nrow][ncol] = 1;
                        grid[nrow][ncol] = '0';
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    bfs(i,j,grid,n,m);
                    count++;
                }
            }
        }

        return count;
    }
};