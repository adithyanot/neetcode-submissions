class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m;
        for(const auto& num:nums){
            m[num] ++;
            
        }
        vector<vector<int>> count(n);
        for(const auto& it:m){
            int key = it.second;
            count[key-1].push_back(it.first);
        }

        vector<int> answer;
        int remaining = k;
        for(int i =n-1;i>=0;i--){
            for(int j=0;j<count[i].size();j++){
                answer.push_back(count[i][j]);
                remaining --;
                if(!remaining){
                    break;
                }
            }
            if(!remaining){
                    break;
                }
        }




        return answer;
        
    }
};
