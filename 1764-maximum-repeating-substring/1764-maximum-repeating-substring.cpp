class Solution {
public:
    int maxRepeating(string s, string word) {
        int ans=0, ct=0;
        int i=0,x=0,j=0,n=s.size(),m=word.size();
        while(x<n){
            if(s[i]==word[j]){
                while(j<m && i<n && s[i]==word[j]){
                    i++;
                    j++;
                }
                if(j==m) ct++;
                else{
                    ans=max(ans,ct);
                    ct=0;
                }
                j=0;
                // cout<<ct<<" ";
            }else{
                // cout<<"- ";
                ans = max(ans, ct);
                ct=0;
                x++;
                i=x;
                j=0;
            }
        }
        ans=max(ans,ct);
        return ans;
    }
};