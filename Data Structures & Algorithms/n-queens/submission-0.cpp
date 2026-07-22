class Solution {

    vector<vector<string>> res;
    bool isvalid(vector<string>& board){
        int count =0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j] == 'Q'){
                    count++;
                }
            }
        }
        return count == board.size();
    }
    bool eligible(vector<string>& board,int row,int col){
        for(int i=0;i<row;i++){
            if(board[i][col] =='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col-1;i>=0&& j>=0;i--,j--){
             if(board[i][j] =='Q'){
                return false;
            }

        }
        for(int i=row-1,j=col+1;i>=0&& j<board.size();i--,j++){
             if(board[i][j] =='Q'){
                return false;
            }

        }
        return true;



    }
    bool backtrack(int n,vector<string>& board,int row,int col){
        if(col ==n){
            return backtrack(n,board,row+1,0);
        }
        if(row ==n){
            if(isvalid(board)){
                res.push_back(board);
                return true;
            }
            return false;
           
        }
        if(eligible(board,row,col)){
            board[row][col] = 'Q';
            backtrack(n,board,row+1,0);
            board[row][col] = '.';
        }
        return backtrack(n,board,row,col+1);

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> bd(n,string(n,'.'));
        backtrack(n,bd,0,0);
        return res;
        
    }
};
