class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    

                }
            }
        }
        int time =0;
        while(!q.empty()){
            int s = q.size();
            vector<vector<int>> curr;
            for(int j=0;j<s;j++){
                vector<int> top = q.front();
                int r = top[0];
                int c = top[1];
                q.pop();
                curr.push_back({r,c});

            }
            time++;
            for(int j=0;j<curr.size();j++){
                int r = curr[j][0];
                int c = curr[j][1];
                for(int i=0;i<4;i++){
                    int row =  r + dir[i][0];
                    int col = c + dir[i][1];
                    if(row<0 || row>=m || col<0 || col >=n || grid[row][col] !=1 ){
                        continue;
                    }
                    grid[row][col] = 2;
                    q.push({row,col});
                

                }
            }
            

        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                    

                }
            }
        }
        if(time>0){
            return time-1;
        }
        return time;

        
    }
};
