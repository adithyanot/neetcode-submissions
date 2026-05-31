class Solution {
public:
    void dfs(vector<vector<char>>& grid,int r,int c){
        if(r<0||c<0||r>=grid.size()||c>= grid[0].size() || grid[r][c] == '0'){
            return;
        }
        grid[r][c] = '0';
        dfs(grid,r+1,c);
        dfs(grid,r,c+1);
        dfs(grid,r-1,c);
        dfs(grid,r,c-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '0'){
                    continue;
                }else{
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;


        
    }
};
