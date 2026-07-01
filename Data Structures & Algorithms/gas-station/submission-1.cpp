class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
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
