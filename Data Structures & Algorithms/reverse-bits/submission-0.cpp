class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int is_one_added =0;
        if(!((n >> 31)&1)){
            is_one_added =1;
            n = n + (1 << 31);
        }
        int ans =0;
        while(n){
            ans = ans <<1;
            ans += n&1;
            n = n>>1;
        }
        if(is_one_added){
            return ans-1;
        }

        return ans;
        
    }
};
