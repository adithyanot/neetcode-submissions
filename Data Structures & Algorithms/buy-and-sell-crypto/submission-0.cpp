class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        if(n == 0 || n ==1){
            return 0;
        }
        int buy =0;
        int sell = 1;
        int max_profit = 0;
        while(buy<n-1 && sell < n && buy < sell){
            int curr_profit = prices[sell] - prices[buy];
            if(curr_profit <=0){
                buy = sell;sell = buy+1;
            }else{
                max_profit = max(max_profit,curr_profit);
                sell++;
            }


        }
        return max_profit;
   
        
    }
};
