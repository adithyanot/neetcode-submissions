class Solution {
public:
    int dfs(vector<vector<int>>& grid,int r,int c){
        if(r<0||c<0||r>=grid.size()||c>= grid[0].size() || grid[r][c] == 0){
            return 0;
        }
        grid[r][c] = 0;
        int l = dfs(grid,r+1,c);
        int u = dfs(grid,r,c+1);
        int ri = dfs(grid,r-1,c);
        int d = dfs(grid,r,c-1);
        return l+u+ri+d+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int maxarea =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    continue;
                }else{
                    int area = dfs(grid,i,j);
                    maxarea = max(area,maxarea);
                }
            }
        }
        return maxarea;
    }
};
