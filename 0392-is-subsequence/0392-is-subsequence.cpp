class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        int ss = s.size(), st = t.size();
        while(i<ss && j<st){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        if(i==ss) return true;
        return false;
    }
};