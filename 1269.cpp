#include "header.h"

/**
 * This is a typical dynamic programming problem.
 * Let's define (i, j) means stading at j after i steps
 * 
 * The status (i, j) can be reached by up to 3 status.
 * 1. (i - 1, j) and operation stay
 * 2. (i - 1, j - 1) and operation Right
 * 3. (i - 1, j + 1) and operation Left
 * 
 * Caution: Be careful about boundaries.
*/

class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int numWays(int steps, int arrLen) {
        // dp[i][j] means how many ways can I stay at j when I move i steps
        // result is dp[steps][0]
        unsigned long long dp[505][505];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = dp[i - 1][j];
                dp[i][j] %= mod;
                if (j > 0) {
                    dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] %= mod;
                }
                if (j + 1 <= arrLen - 1) {
                    dp[i][j] += dp[i - 1][j + 1];
                    dp[i][j] %= mod;
                }
            }
        }
        return dp[steps][0] % mod;
    }
};

int main() {
    cout << Solution().numWays(27, 7);
}