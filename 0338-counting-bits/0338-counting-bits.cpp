class Solution {
public:
    bool isPowerOfTwo(int n)
    {
       if(n==0 || n==1) return false;
       return (ceil(log2(n)) == floor(log2(n)));
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        if(n>=0) ans[0]=0;
        if(n>=1) ans[1]=1;
        if(n>=2) ans[2]=1;
        int prev=2;
        for(int i=3;i<=n;i++){
            if(isPowerOfTwo(i)){
                ans[i]=1;
                prev=i;
            }else{
                int ones=1+ans[(i-prev)];
                ans[i]=ones;
            }
        }
        return ans;
    }
    
};