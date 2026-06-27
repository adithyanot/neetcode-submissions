class Solution {
public:
    unordered_map<string,int> mp;
    int backtrack(vector<int>& nums){
        if(nums.size()==1){
            return nums[0];
        }
        string s ;
        for(auto i:nums){
            s += to_string(i);
        }
        if(mp[s]){
            return mp[s];
        }
        int max_coins =0;
        for(int i=0;i<nums.size();i++){
            int curr_coins = nums[i];
            if(i-1>=0){
                curr_coins *= nums[i-1];
            }
            if(i+1<nums.size()){
                curr_coins *= nums[i+1];
            }
            int temp = nums[i];
            nums.erase(nums.begin()+i);
            curr_coins += backtrack(nums);
            nums.insert(nums.begin()+i,temp);
            max_coins = max(max_coins,curr_coins);

        }
        mp[s] = max_coins;
        return max_coins;

    }
    int maxCoins(vector<int>& nums) {
        int res = backtrack(nums);
        return res;
        
    }
};
