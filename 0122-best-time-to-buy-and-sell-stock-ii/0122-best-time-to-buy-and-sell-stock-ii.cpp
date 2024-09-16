class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int curr = prices[0];
        int ans = 0;
        for(int i=1;i<n;i++){
            if(curr<prices[i]){
                ans += (prices[i]-curr);
            }
            curr = prices[i];
        }
        return ans;
    }
};