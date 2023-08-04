class Solution {
public:
    bool rotateString(string s, string goal) {
        // bool ans=true;
        for(int i=0;i<s.length();i++){
            int k=0;
            for(int j=i;j<i+s.length();j++){
                if(s[j%s.length()]==goal[j-i]) k++;
            }
            if(k==s.length()) return true;
        }
        return false;
    }
};