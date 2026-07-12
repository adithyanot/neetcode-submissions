class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        auto comp = [](vector<int>a, vector<int> b){
           return a[1] -a[0] < b[1] - b[0];

        };
        sort(intervals.begin(),intervals.end(),comp);
        vector<int> res(queries.size(),-1);
        for(int i=0;i<queries.size();i++){
            for(int j=0;j<intervals.size();j++){
                if(queries[i]>= intervals[j][0] && queries[i]<= intervals[j][1]){
                    res[i] = intervals[j][1]-intervals[j][0]+1;
                    break;
                }
            }

        }
        return res;

        
    }
};
