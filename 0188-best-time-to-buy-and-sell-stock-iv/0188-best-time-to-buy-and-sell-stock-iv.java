import java.util.List;
import java.util.ArrayList;

class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        int[][] after = new int[k+1][2];
        int[][] curr = new int[k+1][2];
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
            for(int j=0;j<=k;j++){
                for(int c=0;c<=1;c++){
                    after[j][c]=0;
                    curr[j][c]=0;
                }
            }
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=k;j++){
                for(int c=0;c<=1;c++){
                    if(c==1){
                        curr[j][c]=Math.max(-prices[i]+after[j][0], 0+after[j][1]);
                    }else{
                        curr[j][c]=Math.max(prices[i]+after[j-1][1], 0+after[j][0]);
                    }
                }
            }
            after = curr;
        }
        return after[k][1];
    }
}