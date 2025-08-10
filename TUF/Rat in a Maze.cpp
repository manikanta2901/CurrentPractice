class Solution{
    public:
    vector<string> answer;
    void getAnswer(vector<vector<int>>&grid,int row,int col,string path){
        if(row == grid.size() - 1 && col == grid.size() - 1){
            answer.push_back(path);
            return;
        }   

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,1,-1};
        char directions[4] = {'U','D','R','L'};

        for(int i = 0; i < 4; i++){
            int newX = row + dx[i];
            int newY = col + dy[i];
            if(newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[0].size() || grid[newX][newY] != 1){
                continue;
            }
            grid[newX][newY] = 2;
            getAnswer(grid,newX,newY,path + directions[i]);
            grid[newX][newY] = 1;
        }
    }
    vector<string> findPath(vector<vector<int> > &grid) {
        //your code goes here
        int size = grid.size();
        if(grid[0][0] == 0){
            return answer;
        }
        grid[0][0] = 2;
        getAnswer(grid,0,0,"");
        grid[0][0] = 1; 
        return answer;
    }
};