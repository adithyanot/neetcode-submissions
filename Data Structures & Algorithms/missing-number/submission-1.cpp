class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorr = n;
        for(int i=0;i<nums.size();i++){
            xorr = xorr ^ nums[i] ^ (i);
        }
        return xorr;
        
    }
};
