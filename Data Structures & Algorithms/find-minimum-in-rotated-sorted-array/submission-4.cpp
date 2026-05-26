class Solution {
public:
    int findMin(vector<int> &nums){
        int n = nums.size();
        int l=0;
        int r=n-1;
        int mid;
        int mini =INT_MAX;
        int swit = 1;
        if(n==1){
            return nums[0];
        }
       while(l<=r){
        mid = (l+r)/2;
        mini = min(mini,nums[mid]);
        if (mid == n-1){
            l = 0;
            r = (n-1)/2;
            swit =0;
            continue;
        }
        if(nums[mid]>nums[mid+1]){
            return nums[mid+1];
        }else{
            if(swit){
                l ++;
            }else{
                r--;
            }
            

        }
        

        
    }
    return mini;
    }
};
