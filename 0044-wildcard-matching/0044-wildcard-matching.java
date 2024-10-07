class Solution {
    int[][] dp;
    private boolean isAllStars(String p, int j){
        boolean rt = true;
            for (int k = 0; k <= j; k++) {
                if (p.charAt(k) != '*') {
                    rt = false;
                    break;
                }
            }
            return rt;
    }
    public boolean function(String s, String p, int i, int j) {
        if (j < 0 && i < 0)
            return true;
        if (j < 0 && i >= 0)
            return false;
        if (i < 0 && j >= 0) {
            return isAllStars(p,j);
        }
        if(dp[i][j]!=-1) return (dp[i][j]==1)?true:false;
        if (s.charAt(i) == p.charAt(j) || p.charAt(j) == '?') {
            boolean rt = function(s, p, i - 1, j - 1);
            dp[i][j]=rt?1:0;
            return rt;
        }
        if (p.charAt(j) == '*') {
            boolean st = function(s, p, i - 1, j) || function(s, p, i, j - 1);
            dp[i][j]=(st)?1:0;
            return st;
        }
        dp[i][j]=0;
        return false;
    }

    public boolean isMatch(String s, String p) {
        int n = s.length();
        int m = p.length();
        if(n==0){
            if(isAllStars(p,m-1)) return true;
            else return false;
        }
        if(m==0) return false;
        dp = new int[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=-1;
            }
        }
        function(s, p, n - 1, m - 1);
        return (dp[n-1][m-1]==1);
    }
}