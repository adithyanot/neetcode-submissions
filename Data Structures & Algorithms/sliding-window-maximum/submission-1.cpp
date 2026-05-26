class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<k;i++){
            pq.push(make_pair(nums[i],i));
            
        }
        auto p_first = pq.top();
        ans.push_back(p_first.first);
        for(int r=k;r<nums.size();r++){
            pq.push(make_pair(nums[r],r));
            pair<int,int> p = pq.top();
            int max = p.first;
            int index =p.second;
            while(index<r-k+1){
                pq.pop();
                p = pq.top();
                max = p.first;
                index =p.second;
            }
            ans.push_back(max);

            





        }
        return ans;
        
    }
};
