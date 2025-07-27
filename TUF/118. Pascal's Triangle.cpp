class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > pascal(numRows);
        for(int i = 0; i < numRows; i++){
            pascal.resize(i + 1);
            pascal[i][0] = 1;
            pascal[i][i] = 1;
            for(int j = 0; j < i; j++){
                pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
            }
        }
        return pascal;
    }
};