#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int R = grid.size();
        int C = grid[0].size();

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                
                // When we find land...
                if (grid[i][j] == 1) {
                    
                    // 1. Assume it's completely isolated
                    perimeter += 4;
                    
                    // 2. Check DOWN: If there is land below us, we share an edge.
                    // This removes 2 perimeter walls (1 from us, 1 from them).
                    if (i + 1 < R && grid[i + 1][j] == 1) {
                        perimeter -= 2;
                    }
                    
                    // 3. Check RIGHT: If there is land to our right, we share an edge.
                    if (j + 1 < C && grid[i][j + 1] == 1) {
                        perimeter -= 2;
                    }
                }
            }
        }
        
        return perimeter;
    }
};