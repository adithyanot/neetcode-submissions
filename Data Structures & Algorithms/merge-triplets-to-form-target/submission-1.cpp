class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        for(int i=0;i<triplets.size();i++){
            if(triplets[i][0] > target[0] || triplets[i][1] > target[1]||triplets[i][2] > target[2]){
                triplets.erase(triplets.begin()+i);
                i--;
            }

        }
        vector<int> maxi(3,0);
        for(int i=0;i<triplets.size();i++){
            for(int j=0;j<3;j++){
                maxi[j] = max(maxi[j],triplets[i][j]);
            }

        }
        for(int i=0;i<3;i++){
            if(maxi[i]!=target[i]){
                return false;
            }
        }
        return true;


        
    }
};
