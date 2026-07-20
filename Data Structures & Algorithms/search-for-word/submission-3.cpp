class Solution {
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(vector<vector<char>>& board, string word, int row,int col, int pos){
        if(row<0 || row>=board.size()||col<0||col>=board[0].size()){
            return false;
        }
        if(pos == word.size()){
            return true;
        }
        if(board[row][col] == word[pos]){
            if(pos == word.size()-1){
                return true;
            }
            char temp =  board[row][col];
            board[row][col] = '#';
            for(int i=0;i<dir.size();i++){
                    if(dfs(board,word,row+dir[i][0],col+dir[i][1],pos+1)){
                    return true;
                }
            
                
            }
            board[row][col] =temp;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                    if(dfs(board,word,i,j,0)){
                        return true;
                    }
                
            }
        }
        return false;
        
    }
};
