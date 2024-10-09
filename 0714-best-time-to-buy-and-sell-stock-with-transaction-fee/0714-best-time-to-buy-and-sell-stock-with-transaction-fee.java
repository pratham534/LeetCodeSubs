class Solution {
    public int maxProfit(int[] prices, int fee) {
        int[] curr = new int[2];
        int[] next = new int[2];
        int n = prices.length;
        for (int buy = 0; buy <= 1; buy++) {
            curr[buy] = 0;
            next[buy] = 0;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 1; buy >=0; buy--) {
                if (buy == 1) {
                    int buyYes = -prices[i] + next[0];
                    int buyNo = next[1];
                    curr[buy] = Math.max(buyYes, buyNo);
                } else {
                    int sellYes = (prices[i] - fee) + next[1];
                    int sellNo = next[0];
                    curr[buy] = Math.max(sellYes, sellNo);
                }
            }
            next = curr.clone();
        }
        return next[1];
    }
}