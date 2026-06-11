class Solution {
public:
    void backtrack(vector<int>& nums, int target, vector<vector<int>>& res, 
             vector<int>& subset, int start) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }
        if (target < 0) return;
        int i = start;
        while(i < nums.size()) {
            subset.push_back(nums[i]);
            backtrack(nums, target - nums[i], res, subset, i+1);  
            subset.pop_back(); 
            i++;
            while(i < nums.size() && nums[i]==nums[i-1]){
                i++;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates, target, res, subset, 0);
        // set<vector<int>>s(res.begin(),res.end());
        // res.assign(s.begin(),s.end());


        return res;
        
    }
};
