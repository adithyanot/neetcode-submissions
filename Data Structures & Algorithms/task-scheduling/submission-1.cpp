class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        int maxi=0;
        int m = tasks.size();
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
            maxi = max(maxi,mp[tasks[i]]);
        }
        int count=0;
        for(auto i:mp){
            if(i.second == maxi){
                count++;
            }

        }
        int res = maxi*(n+1) -n + count-1;
        return  max(res,m);
        
        
    }
};
