class Solution {
    // List<List<Integer>> dp;
    // int[][] d;

    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[] curr = new int[2];
        int[] next = new int[2];
        int[] fnext = new int[2];
        for (int j = 0; j <= 1; j++) {
            curr[j] = 0;
            next[j] = 0;
            fnext[j] = 0;
        }
        for (int i = n - 1; i >= 0; i--) {
            int buyYes = -prices[i] + next[0];
            int buyNo = 0 + next[1];
            curr[1] = Math.max(buyYes, buyNo);
            int sellYes = prices[i] + fnext[1];
            int sellNo = 0 + next[0];
            curr[0] = Math.max(sellYes, sellNo);
            fnext = next.clone();
            next = curr.clone();
        }
        return curr[1];
    }
}