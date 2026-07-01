class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        int total_gas =0;
        int total_cost = 0;
        for(int i=0;i<n;i++){
            total_gas+= gas[i];
            total_cost+= cost[i];
        }
        if(total_gas<total_cost){
            return -1;
        }
        for(int i=0;i<n;i++){
            if(cost[i]>gas[i]){
                continue;
            }else{
                int curr = i+1;
                curr = curr % n;
                int curr_gas = gas[i]-cost[i];
                while(curr!=i){
                    if(curr_gas + gas[curr] - cost[curr]>=0){
                        curr_gas = curr_gas + gas[curr] - cost[curr];
                        curr++;
                        curr = curr % n;
                    }else{
                        break;
                    }

                }
                if(curr == i){
                    return i;
                }

            }
        }
        return -1;
        
      
        
    }
};
