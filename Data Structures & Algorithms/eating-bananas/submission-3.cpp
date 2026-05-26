class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int m = INT_MIN;
        for(int i=0;i<n;i++){
            m = max(m,piles[i]);
        }
       
        for(double i=1;i<m;i++){
            long long total =0;
            for(int j=0;j<n;j++){
                int hours = ceil(piles[j]/i);
                total += hours;
            }
            if(total<=h){
                return i;
            }


        }
      

        
    }
};
