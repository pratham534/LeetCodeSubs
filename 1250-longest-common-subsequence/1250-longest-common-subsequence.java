class Solution {
    private int[][] dp;
    public int findLength(int i, int j, String text1, String text2){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1.charAt(i)==text2.charAt(j)){
            return dp[i][j] = (1 + findLength(i-1, j-1, text1, text2));
        }
        return dp[i][j] = Math.max(findLength(i,j-1,text1,text2),findLength(i-1,j,text1,text2));
    }
    public int longestCommonSubsequence(String text1, String text2) {
        int n = text1.length();
        int m = text2.length();
        dp = new int[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=-1;
            }
        }
        int ans = findLength(n-1,m-1,text1,text2);
        return ans;
    }
}