class Solution {
public:
    int dfs(vector<vector<int>>& matrix,int i,int j,vector<vector<int>> &dp){
        if(i<0 || i>=matrix.size()||j<0||j>=matrix[0].size()){
            return 0;
        }
        if(dp[i][j]){
            return dp[i][j];
        }
        dp[i][j] =1;
        if(j+1 < matrix[0].size() && matrix[i][j] <matrix[i][j+1]){
            dp[i][j] = max(dp[i][j],1+dfs(matrix,i,j+1,dp));
        }
        if(j-1>=0 && matrix[i][j] <matrix[i][j-1]){
            dp[i][j] = max(dp[i][j],1+dfs(matrix,i,j-1,dp));
        }
        if(i+1 < matrix.size() && matrix[i][j] <matrix[i+1][j]){
            dp[i][j] = max(dp[i][j],1+dfs(matrix,i+1,j,dp));
        }
        if(i-1 >=0 &&  matrix[i][j] <matrix[i-1][j]){
            dp[i][j] = max(dp[i][j],1+dfs(matrix,i-1,j,dp));
        }
        return dp[i][j];


    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int maxlen =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxlen = max(maxlen,dfs(matrix,i,j,dp));

            }
        }
        return maxlen;
        
    }
};
