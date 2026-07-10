/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        auto comp = [](Interval a, Interval b){
            if(a.start == b.start){
                return a.end < b.end;
            }
            return a.start < b.start;
        };
        sort(intervals.begin(),intervals.end(),comp);
        int n = intervals.size();
        int i=0;
        while(i<n-1){
            if(intervals[i].end > intervals[i+1].start){
                return false;
            }
            i++;
        }
        return true;
        
    }
};
