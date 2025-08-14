class Solution
{
public:
    int celebrity(vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid.size();
        vector<int>inDegree(m,0),outDegree(m,0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    outDegree[i]++;
                    inDegree[j]++;
                }
            }
        }
        for(int i = 0; i < m; i++){
            if(inDegree[i] == m - 1 && outDegree[i] == 0){
                return i;
            }
        }
        return -1;
    }
};
