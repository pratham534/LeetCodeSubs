class Solution {
    private int[][] dp;
    public int findLength(int n, int m, String text1, String text2){
        // if(i<=0 || j<=0) return 0;
        // if(dp[i][j]!=-1) return dp[i][j];
        // if(text1.charAt(i-1)==text2.charAt(j-1)){
        //     return dp[i][j] = (1 + findLength(i-1, j-1, text1, text2));
        // }
        // return dp[i][j] = Math.max(findLength(i,j-1,text1,text2),findLength(i-1,j,text1,text2));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1.charAt(i-1)==text2.charAt(j-1)){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    public String printLCS(String text1, int n, String text2, int m){
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=m;j++){
        //         System.out.print(dp[i][j]+" ");
        //     }
        //     System.out.println();
        // }
        StringBuilder str = new StringBuilder();
        int i=n, j=m;
        while(i>0 && j>0){
            if(text1.charAt(i-1)==text2.charAt(j-1)){
                str.append(text1.charAt(i-1));
                i--;
                j--;
            }else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
        return str.reverse().toString();
    }
    public int longestCommonSubsequence(String text1, String text2) {
        int n = text1.length();
        int m = text2.length();
        dp = new int[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j]=-1;
                if(i==0 || j==0) dp[i][j]=0;
            }
        }
        int ans = findLength(n,m,text1,text2);
        System.out.println(printLCS(text1, n, text2, m));
        return ans;
    }
}