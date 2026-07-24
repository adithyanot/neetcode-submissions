class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<vector<int>>> mp;
        for(int i=0;i<times.size();i++){
            mp[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<int> visited(n+1,0);
        queue<int> q;
        q.push(k);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int i=0;i<mp[temp].size();i++){
                if(mp[temp][i][0] == k){
                    continue;
                }
                if(visited[mp[temp][i][0]]){
                    if(mp[temp][i][1] + visited[temp] < visited[mp[temp][i][0]]){
                        visited[mp[temp][i][0]] = mp[temp][i][1] + visited[temp];
                        q.push(mp[temp][i][0]);
                    }
                }else{
                    visited[mp[temp][i][0]] = mp[temp][i][1] + visited[temp];
                    q.push(mp[temp][i][0]);

                }

                
            }

        }
        int max_time =0;
        for(int i=1;i<visited.size();i++){
            if(visited[i] == 0 && i !=k ){
                return -1;
            }
            max_time = max(max_time,visited[i]);
        }
        return max_time;


        
    }
};
