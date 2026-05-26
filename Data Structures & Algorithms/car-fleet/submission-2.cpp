class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
        mp[position[i]] = speed[i];
       }

        sort(position.begin(),position.end());
        int total_fleets =n;
        stack<double> st;
       for(int i=n-1;i>=0;i--){
        int pos1 = position[i];
        int speed1 = mp[pos1];
        double time1 = (double)(target-pos1)/speed1;
        while(!st.empty() && st.top()<time1){
            st.pop();
        }
        if(st.empty()){
            st.push(time1);
            continue;
        }else{
            total_fleets--;
            st.push(time1);

        }
       
        
    
        
        



       }
       return total_fleets;
        
    }
};
