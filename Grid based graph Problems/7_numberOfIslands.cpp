class Solution {
  public:
    void bfs(vector<vector<char>>& grid,int sr,int sc,int m,int n){
        
        queue<pair<int,int>>q;
        q.push({sr,sc});
        grid[sr][sc]='$';
    
        // 1. Standard BFS - expanding from the boundary "seeds" (diagonal is also direction this time)
        while (!q.empty()) {
            auto [x, y] = q.front(); 
            q.pop();
            
          for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i==0 && j==0) continue;
                
                int nx=x+i;
                int ny=y+j;
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 'L') {
                    grid[nx][ny] = '$';
                    q.push({nx, ny});
                }
            }
         }
            
        }
        return;
    }
    
    //Standard DFS
    void dfs(vector<vector<char>>& grid,int x,int y,int m,int n){
        
        if(x<0||x>=m||y<0||y>=n||grid[x][y]!='L') return;
        
        grid[x][y]='$';//mark visited
        
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                
                if(i==0 && j==0) continue;
                
                int newX=x+i;
                int newY=y+j;
                
                dfs(grid,newX,newY,m,n);
            }
        }
        return;
        
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();
        int island=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='L'){
                    bfs(grid,i,j,m,n);
                    island++;
                }
            }
        }
        return island;
    }
};
