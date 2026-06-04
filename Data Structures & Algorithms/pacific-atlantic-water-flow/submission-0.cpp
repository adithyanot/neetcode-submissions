class Solution {
public:
    
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>&heights, int r , int c,vector<vector<int>>&ocean ){
        ocean[r][c] =1;
        for(int i=0;i<4;i++){
            int row = r+directions[i][0];
            int col = c+directions[i][1];
            if(row>=0 && row<heights.size() && col>=0 && col<heights[0].size() && heights[r][c]<=heights[row][col] && !ocean[row][col]){
                dfs(heights,row,col,ocean);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> atlantic(m,vector<int>(n));
        vector<vector<int>> pacefic(m,vector<int>(n));
        for(int i=0;i<m;i++){
            dfs(heights,i,n-1,atlantic);
            dfs(heights,i,0,pacefic);
        }
        for(int i=0;i<n;i++){
            dfs(heights,m-1,i,atlantic);
            dfs(heights,0,i,pacefic);
        }
        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacefic[i][j]==1 && atlantic[i][j]==1){
                    res.push_back({i,j});
                }
            }
        }
        return res;

    }
};
