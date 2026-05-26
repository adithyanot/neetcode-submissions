class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char,int>> rows(9);
        vector<unordered_map<char,int>> cols(9);
        vector<unordered_map<char,int>> box(9);


        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char key = board[i][j];
                if( key != '.'){
                    rows[i][key] ++;
                    cols[j][key] ++;
                    int boxi = i/3 ;
                    boxi *= 3;
                    boxi += j/3;
                    box[boxi][key]++;
                }


            }
        }
        for(int i=0;i<9;i++){
            for(int j=1; j<10;j++){
                auto k = to_string(j);
                cout<<rows[i][k[0]];
                if(rows[i][k[0]]>1 ||cols[i][k[0]]>1 ||box[i][k[0]]>1){
                    return false;

                }
            }
        }
        return true;
        
    }
};
