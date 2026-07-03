class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> maxi(3,0);
        for(int i=0;i<triplets.size();i++){
            if(triplets[i][0] > target[0] || triplets[i][1] > target[1]||triplets[i][2] > target[2]){
                continue;
            }else{
                for(int j=0;j<3;j++){
                    maxi[j] = max(maxi[j],triplets[i][j]);
                }
            }

        }
        return maxi == target;
        
       

        
    }
};
