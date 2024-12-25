#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxChocolates(vector<vector<int>>& grid, int row, int col1, int col2, int n, int m) {
    if (row == n) return 0;
    if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m) return INT_MIN;

    int result = 0;
    for (int d1 = -1; d1 <= 1; ++d1) {
        for (int d2 = -1; d2 <= 1; ++d2) {
            int newCol1 = col1 + d1;
            int newCol2 = col2 + d2;
            result = max(result, maxChocolates(grid, row + 1, newCol1, newCol2, n, m));
        }
    }

    if (col1 == col2) {
        result += grid[row][col1];
    } else {
        result += grid[row][col1] + grid[row][col2];
    }

    return result;
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3, 4},
        {0, 5, 6, 7},
        {8, 9, 10, 11},
        {12, 13, 14, 15}
    };

    int n = grid.size();
    int m = grid[0].size();

    int result = maxChocolates(grid, 0, 0, m - 1, n, m);
    cout << "Maximum chocolates collected: " << result << endl;

    return 0;
}