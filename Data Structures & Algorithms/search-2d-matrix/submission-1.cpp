class Solution {
public:
    bool binarsearch(vector<int>arr,int target){
        int l =0;
        int r = arr.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(arr[mid] == target){
                return true;
            }else if(arr[mid] <= target){
                l = mid+1;

            }else{
                r = mid-1;
            }

        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m-1;
        int mid;
        while(low<=high){
             mid = (low+high)/2;
            if(matrix[mid][0]<=target && matrix[mid][n-1]>=target){
                return binarsearch(matrix[mid],target);
            }else if(matrix[mid][0]>target){
                high = mid -1;
            }else if(matrix[mid][n-1]<target){
                low = mid+1;
            }

        }
        return binarsearch(matrix[mid],target);
        

    }
};
