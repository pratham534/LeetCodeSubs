class Solution {
    public int maxProfit(int[] prices) {
        int ans1 = 0, ans2 = 0;
        int n = prices.length;
        List<Integer> dp1 = new ArrayList<>();
        List<Integer> dp2 = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            dp1.add(0);
            dp2.add(0);
        }
        dp1.set(0, 0);
        dp2.set(n - 1, 0);
        int mini = prices[0];
        int maxi = 0;
        for (int i = 1; i < n; i++) {
            ans1 = Math.max(ans1, (prices[i] - mini));
            dp1.set(i, ans1);
            mini = Math.min(prices[i], mini);
        }
        for (int i = n - 2; i >= 0; i--) {
            ans2 = Math.max(ans2, maxi - prices[i + 1]);
            dp2.set(i, ans2);
            maxi = Math.max(maxi, prices[i + 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, dp1.get(i) + dp2.get(i));
        }
        return ans;
    }
}