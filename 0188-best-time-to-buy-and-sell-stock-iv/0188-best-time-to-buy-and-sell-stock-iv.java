import java.util.List;
import java.util.ArrayList;

class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        // int[][] after = new int[k + 1][2];
        // int[][] curr = new int[k + 1][2];
        List<List<Integer>> after = new ArrayList<>();
        List<List<Integer>> curr = new ArrayList<>();
        for (int j = 0; j <= k; j++) {
            List<Integer> temp = new ArrayList<>();
            for (int c = 0; c <= 1; c++) {
                temp.add(0);
            }
            after.add(temp);
            curr.add(temp);
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {
                for (int c = 0; c <= 1; c++) {
                    if (c == 1) {
                        int buy = -prices[i]+after.get(j).get(0);
                        int notBuy = 0 + after.get(j).get(1);
                        curr.get(j).set(c, Math.max(buy, notBuy));
                        // curr[j][c] = Math.max(-prices[i] + after[j][0], 0 + after[j][1]);
                    } else {
                        int sell = prices[i]+after.get(j-1).get(1);
                        int notSell = 0 + after.get(j).get(0);
                        curr.get(j).set(c, Math.max(sell, notSell));
                        // curr[j][c] = Math.max(prices[i] + after[j - 1][1], 0 + after[j][0]);
                    }
                }
            }
            after = curr;
        }
        return after.get(k).get(1);
    }
}