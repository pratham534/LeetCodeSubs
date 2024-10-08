class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        List<Integer> dp = new ArrayList<>(n);
        for(int i=0;i<n;i++){
            dp.add(0);
        }
        int ans =0;
        dp.set(0,prices[0]);
        for(int i=1;i<n;i++){
            if(prices[i]>dp.get(i-1)){
                ans += (prices[i]-dp.get(i-1));
            }
            dp.set(i,prices[i]);
        }
        return ans;
    }
}