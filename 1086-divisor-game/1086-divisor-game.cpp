class Solution {
public:
    bool divisorGame(int n) {
        vector<vector<bool>> dp(2,vector<bool>(n+1));
        for(int i=0;i<=n;i++){
            dp[0][i]=false;
            dp[1][i]=true;
        }
        dp[0][1]=false;
        dp[1][1]=true;
        // dp[0][2]=true;
        // dp[1][2]=false;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                if(i%j == 0){
                    dp[0][i] = dp[0][i] | dp[1][(i-j)];
                    dp[1][i] = dp[1][i] & dp[0][(i-j)];
                }
            }
        }
        return dp[0][n];
    }
};