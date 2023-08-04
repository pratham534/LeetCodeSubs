class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;
        int a = 0;
        int b = 0;
        while(a<=m && b<=n){
            // int j=0;
            for(int i=b;i<=n;i++){
                ans.push_back(matrix[a][i]);
            }
            a++;
            for(int i=a;i<=m;i++){
                ans.push_back(matrix[i][n]);
            }
            n--;
            if(a<=m){
                for(int i=n;i>=b;i--){
                    ans.push_back(matrix[m][i]);
                }
                m--;
            }
            if(b<=n){
                for(int i=m;i>=a;i--){
                    ans.push_back(matrix[i][b]);
                }
                b++;
            }
        }
        return ans;
    }
};