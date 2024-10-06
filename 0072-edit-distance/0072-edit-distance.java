class Solution {
    private int[][] dp;
    public int function(String word1, String word2, int i, int j){
        if(j<0 && i<0) return 0;
        if(j<0 && i>=0) return i+1;
        if(i<0 && j>=0) return j+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1.charAt(i) == word2.charAt(j)){
            return dp[i][j]=function(word1, word2, i-1, j-1);
        }
        int deleteOp = 1+function(word1,word2,i-1,j);
        int replaceOp = 1+function(word1,word2,i-1,j-1);
        int insertOp = 1+function(word1,word2,i,j-1);
        return dp[i][j]=Math.min(deleteOp, Math.min(replaceOp, insertOp));
    }
    public int minDistance(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();
        dp = new int[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=-1;
            }
        }
        int ans = function(word1,word2,n-1,m-1);
        // System.out.println(dp[n-1][m-1]);
        return ans;
    }
}