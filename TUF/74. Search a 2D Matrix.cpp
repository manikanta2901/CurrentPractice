class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0,j = 0;
        while(i < m){
            if(matrix[i][0] <= target && target <= matrix[i][n - 1]){
                if(binary_search(matrix[i].begin(),matrix[i].end(),target)){
                    return true;
                }
            }
            i++;
        }
        return false;
    }
};