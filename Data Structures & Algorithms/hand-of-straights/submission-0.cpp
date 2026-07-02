class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()% groupSize){
            return false;
        }
        unordered_map<int,int>count;
        for(auto i:hand){
            count[i]++;
        }
        sort(hand.begin(),hand.end());
        for(int i=0;i<hand.size();i++){
            if(count[hand[i]] != 0){
                for(int j=hand[i];j<hand[i]+groupSize;j++){
                    if(count[j]==0){
                        return false;
                    }
                    count[j]--;

                }
            }
        }
        return true;

        
    }
};
