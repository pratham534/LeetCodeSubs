import java.util.List;
import java.util.ArrayList;

class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        int[][][] dp = new int[n+1][k+1][2];
        // List<List<List<Integer>>> dp = new ArrayList<>();
        // for(int i=0;i<=n;i++){
        //     List<List<Integer>> dp0 = new ArrayList<>();
        //     for(int j=0;j<=k;j++){
        //         List<Integer> dp1 = new ArrayList<>();
        //         for(int c=0;c<=1;c++){
        //             dp1.add(0);
        //         }
        //         dp0.add(dp1);
        //     }
        //     dp.add(dp0);
        // }
        for(int i=n;i>=0;i--){
            for(int j=0;j<=k;j++){
                for(int c=0;c<=1;c++){
                    dp[i][j][c]=0;
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=k;j++){
                for(int c=0;c<=1;c++){
                    if(c==1){
                        dp[i][j][c]=Math.max(-prices[i]+dp[i+1][j][0], 0+dp[i+1][j][1]);
                    }else{
                        dp[i][j][c]=Math.max(prices[i]+dp[i+1][j-1][1], 0+dp[i+1][j][0]);
                    }
                }
            }
        }
        return dp[0][k][1];
    }
}