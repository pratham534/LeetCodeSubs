class Solution {
public:
    bool divisorGame(int n) {
        vector<vector<int>> dp(2,vector<int>(n+1,-1));
        dp[0][1]=false;
        dp[1][1]=true;
        function<bool(int,int)> func = [&](int curr, int turn)->bool{
            if(curr==2){
                if(turn==0) return true;
                else return false;
            }
            if(dp[turn][curr]!=-1){
                return dp[turn][curr];
            }
            vector<int> ans(2);
            ans[0]=0;
            ans[1]=1;
            for(int i=1;i<curr;i++){
                if(curr%i == 0){
                    if(turn==0) ans[turn] |= func((curr-i), (turn^1));
                    else ans[turn] &= func((curr-i),(turn^1));
                }
            }
            return dp[turn][curr]=ans[turn];
        };
        dp[0][n]=func(n, 0);
        return dp[0][n];
    }
};