class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length()<=numRows || numRows==1) return s;
        string ans="";
        vector<string> ansv(numRows, "");
        int j=0, flag=0;
        for(int i=0;i<s.length();i++){
            if(j==0){
                j=0;
                flag=0;
            }
            if(j==numRows-1){
                j=numRows-1;
                flag=1;
            }
            ansv[j] += s[i];
            if(flag==0){
                j++;
            }else{
                j--;
            }
        }
        for(auto x : ansv){
            // cout<<x<<" ";
            ans+=x;
        }
        // cout<<endl;
        return ans;
    }
};