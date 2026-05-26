class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> arr;
        for (int i=1;i<nums.size()-1;i++){
            int l =0;
            int r = nums.size()-1;
            while(l<i && i<r){
                // cout<<l<<" "<<i<<" "<<r<<endl;
                if(nums[l]+nums[i]+nums[r] ==0){
                    arr.insert({nums[l],nums[i],nums[r]});
                    l++;
                    r--;

                }else if(nums[l]+nums[i]+nums[r] > 0){
                    r--;
                }else{
                    l++;
                }
            }

        }
        for(const auto&s:arr){
            ans.push_back(s);
        }
        
        return ans;
    }
};
