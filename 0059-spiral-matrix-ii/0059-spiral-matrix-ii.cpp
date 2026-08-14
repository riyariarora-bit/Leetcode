class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int top = 0, down = n - 1;
        int left = 0, right = n - 1;
        int currElement = 1;

        while (currElement <= n * n) {
            // move left to right, row = top fixed
            for (int c = left; c <= right; c++)
                matrix[top][c] = currElement++;
            top++;

            // move top to down, col = right fixed
            for (int r = top; r <= down; r++)
                matrix[r][right] = currElement++;
            right--;

            // move right to left, row = down fixed
            for (int c = right; c >= left && currElement <= n * n; c--)
                matrix[down][c] = currElement++;
            down--;

            // move down to top, col = left fixed
            for (int r = down; r >= top && currElement <= n * n; r--)
                matrix[r][left] = currElement++;
            left++;
        }

        return matrix;
    }
};