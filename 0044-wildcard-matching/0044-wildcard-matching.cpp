class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, s, p, dp);
    }

private:
    bool solve(int i, int j, string &s, string &p,
               vector<vector<int>> &dp) {

        // Base Cases
        if (i < 0 && j < 0)
            return true;

        if (i >= 0 && j < 0)
            return false;

        if (i < 0 && j >= 0)
            return isAllStars(p, j);

        // Already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        // Current characters match or '?'
        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);

        // Current pattern character is '*'
        if (p[j] == '*')
            return dp[i][j] = solve(i - 1, j, s, p, dp) ||
                              solve(i, j - 1, s, p, dp);

        return dp[i][j] = false;
    }

    bool isAllStars(string &p, int j) {
        for (int k = 0; k <= j; k++) {
            if (p[k] != '*')
                return false;
        }
        return true;
    }
};