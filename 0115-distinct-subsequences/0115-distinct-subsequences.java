class Solution {
    private int[][] dp;
    public int function(String s, String t, int i, int j){
        if(j<=0) return 1;
        if(i<=0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s.charAt(i-1)==t.charAt(j-1)){
            return dp[i][j]=function(s,t,i-1,j-1)+function(s,t,i-1,j);
        }
        return dp[i][j]=function(s,t,i-1,j);
    }
    public int numDistinct(String s, String t) {
        int n=s.length(), m=t.length();
        dp = new int[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(j==0) dp[i][j]=1;
                else dp[i][j]=-1;
            }
        }
        int ans = function(s,t,n,m);
        System.out.println(ans);
        System.out.println(dp[n][m]);
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=m;j++){
        //         System.out.print(dp[i][j]+" ");
        //     }
        //     System.out.println();
        // }
        return dp[n][m];
    }
}