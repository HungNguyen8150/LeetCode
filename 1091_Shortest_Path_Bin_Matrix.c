#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int dist;
} Node;

int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize) {
    
    int n = gridSize;
    
    // If start or end is blocked
    if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
        return -1;
    
    // 8 directions
    int directions[8][2] = {
        {-1,-1},{-1,0},{-1,1},
        {0,-1},        {0,1},
        {1,-1},{1,0},{1,1}
    };
    
    // Maximum possible cells = n*n
    Node* queue = (Node*)malloc(n * n * sizeof(Node));
    int front = 0, back = 0;
    
    // Start from (0,0)
    queue[back++] = (Node){0, 0, 1};
    grid[0][0] = 1;  // mark visited
    
    while (front < back) {
        Node curr = queue[front++];
        
        // If we reached bottom-right
        if (curr.row == n-1 && curr.col == n-1) {
            free(queue);
            return curr.dist;
        }
        
        for (int i = 0; i < 8; i++) {
            int nr = curr.row + directions[i][0];
            int nc = curr.col + directions[i][1];
            
            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < n &&
                grid[nr][nc] == 0) {
                
                grid[nr][nc] = 1;  // mark visited
                queue[back++] = (Node){nr, nc, curr.dist + 1};
            }
        }
    }
    
    free(queue);
    return -1;
}
