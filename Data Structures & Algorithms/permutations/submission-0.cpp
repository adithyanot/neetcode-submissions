class Solution {
public:
    void backtrack(vector<int>& nums,vector<vector<int>>&res,vector<int>&subset,set<int>&visit){
        if(subset.size()==nums.size()){
            res.push_back(subset);
        }
        for(int i=0;i<nums.size();i++){
            if(visit.find(nums[i]) == visit.end()){
                subset.push_back(nums[i]);
                visit.insert(nums[i]);
                backtrack(nums,res,subset,visit);
                visit.erase(nums[i]);
                subset.pop_back();
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>subset;
        set<int>visit;
        backtrack(nums,res,subset,visit);
        return res;

        
    }
};
