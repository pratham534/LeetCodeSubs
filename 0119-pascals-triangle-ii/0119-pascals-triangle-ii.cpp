class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle;
        for(int i=0;i<=rowIndex;i++){
            triangle.push_back(vector<int>(i+1,1));
        }
        for(int i=2;i<=rowIndex;i++){
            for(int j=1;j<triangle[i].size()-1;j++){
                triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];
            }
        }
        return triangle[rowIndex];
    }
};