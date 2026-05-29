class Solution {
public:
    class Compare{
        public:
        bool operator()(vector<int>a,vector<int>b){
            if(pow(a[0],2) +pow(a[1],2)< pow(b[0],2) + pow(b[1],2)){
                return false;
            }
            return true;

        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,Compare > pq;
        for(int i=0;i<points.size();i++){
            pq.push(points[i]);
        }
        vector<vector<int>> res;
        for(int i=0;i<k;i++){
            vector<int> top = pq.top();
            pq.pop();
            res.push_back(top);
        }
        return res;
        
        
    }
};
