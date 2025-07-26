class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i;
        int minprices=prices[0];
        int maxProfit=0;
        int n=prices.size();
        for( i=1;i<n;i++){
            int cost=prices[i]-minprices;
            maxProfit=max(maxProfit,cost);
            minprices=min(minprices,prices[i]);
        }
        return maxProfit;
        
    }
};