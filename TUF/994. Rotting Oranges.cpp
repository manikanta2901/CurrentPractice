struct Node{
    int x;
    int y;
    int time;
    Node(int _x,int _y,int t){
        x = _x;
        y = _y;
        time = t;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int countFresh = 0;
        int maxTime = 0;
        queue<Node*> store;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // at time zero all the rotten oranges
                if(grid[i][j] == 2){
                    store.push(new Node(i,j,0));
                }else if(grid[i][j] == 1){
                    countFresh++;
                }
            }
        }

        if(countFresh == 0){
            return 0;
        }

        // neighbours
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while(!store.empty()){
            int size= store.size();
            while(size--){
                Node* node = store.front();
                int X = node->x;
                int Y = node->y;
                int t = node->time;
                store.pop();
                // visiting its neighbours
                for(int i = 0; i < 4; i++){
                    int newX = X + dx[i];
                    int newY = Y + dy[i];

                    // valid neighbour
                    if(newX < 0 || newY < 0 || newX >= m || newY >= n || grid[newX][newY] != 1){
                        continue;
                    }
                    // visited
                    grid[newX][newY] = -1;
                    store.push(new Node(newX,newY, t + 1));
                    countFresh--;
                }
            }
            maxTime++;
        }

        return (countFresh == 0) ? (maxTime - 1) : -1;
    }
};