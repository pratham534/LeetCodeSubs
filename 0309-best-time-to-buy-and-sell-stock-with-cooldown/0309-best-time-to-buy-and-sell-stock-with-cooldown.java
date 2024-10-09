class Solution {
    List<List<Integer>> dp;
    int[][] d;

    public int maxProfit(int[] prices) {
        int n = prices.length;
        dp = new ArrayList<>();
        d = new int[n+2][2];
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=1;j++){
                d[i][j]=0;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    int buyYes = -prices[i]+d[i+1][0];
                    int buyNo = 0 + d[i+1][1];
                    d[i][buy] = Math.max(buyYes, buyNo);
                }else{
                    int sellYes = prices[i] + d[i + 2][1];
                    int sellNo = 0 + d[i + 1][0];
                    d[i][buy]=Math.max(sellYes, sellNo);
                }
            }
        }
        return d[0][1];
    }
}