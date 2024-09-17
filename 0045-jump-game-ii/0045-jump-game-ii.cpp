class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n-1]=0;
        function<int(int)> jump2 = [&](int i)->int{
            if(i==n-1) return 0;
            if(dp[i]!=-1) return dp[i];
            int minJumps = n;
            for(int j=i+1;j<=(i+nums[i]) && j<n;j++){
                minJumps = min(minJumps, jump2(j)+1);
            }
            return dp[i]=minJumps;
        };
        jump2(0);
        return dp[0];
    }
};