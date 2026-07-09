class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count =0;
        auto comp = [&](vector<int>a,vector<int>b){
            if(a[0] == b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        };
        sort(intervals.begin(),intervals.end(),comp);
        int i=0;
        while(i<n-1){
            if(intervals[i][1] <= intervals[i+1][0]){
                i++;
            }else{
                count++;
                if(intervals[i][1] <= intervals[i+1][1]){
                    intervals[i+1][0] = intervals[i][0];
                    intervals[i+1][1] = intervals[i][1];
                }
                i++;

            }
        }
        return count;
        
    }
};
