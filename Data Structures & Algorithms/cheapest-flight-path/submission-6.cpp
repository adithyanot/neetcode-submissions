class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<vector<int>>> mp;
        for(int i=0;i<flights.size();i++){
            mp[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int>cost(n, INT_MAX);
        
        cost[src] =0;
        queue<int> fronty;
        fronty.push(src);
        for(int i=0;i<k+1;i++){
            vector<int>new_cost = cost;
            int s = fronty.size();
            while(s>0){
                int curr = fronty.front();
                fronty.pop();
                for(int j=0;j<mp[curr].size();j++){
                    if(cost[curr] + mp[curr][j][1] < new_cost[mp[curr][j][0]]){
                        new_cost[mp[curr][j][0]] = cost[curr] + mp[curr][j][1];
                        fronty.push(mp[curr][j][0]);

                    }
                }
                s--;
            }
            cost = new_cost;
        }
        if(cost[dst]==INT_MAX){
            return -1;
        }
        return cost[dst];


        
    }
};
