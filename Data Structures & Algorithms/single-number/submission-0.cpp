class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sol =0;
        for(auto i:nums){
            sol = sol^i;
        }
        return sol;
    }
};
