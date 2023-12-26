#include "header.h"

class Solution {
    int mod = 1e9 + 7;
    int dp[35][1005];   // dp[i][j] = number of solutions of combining value j with i dice
public:
    int numRollsToTarget(int n, int k, int target) {
        // DFS TLE
        // Let's consider DP
        for (int i = 1; i <= k; i++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                for (int val = 1; val <= k; val++) {
                    if (j <= val) {
                        continue;
                    }
                    dp[i][j] += dp[i - 1][j - val];
                    dp[i][j] %= mod;
                }
            }
        }
        return dp[n][target] % mod;
    }
};

// DFS: TLE
// class Solution {
//     int mod = 1e9 + 7;
//     int K;
//     int num;
//     int ans;
// public:
//     int numRollsToTarget(int n, int k, int target) {
//         // this problem can use DFS
//         // data range [0, 30]
//         K = k;
//         num = n;
//         ans = 0;
//         traverse(0, target);
//         return ans;
//     }
//     void traverse(int idx, int left) {
//         if ((num - idx) * K < left || (num - idx) > left) {
//             return;
//         }
//         if (idx == num && left == 0) {
//             ans++;
//             return;
//         }
//         for (int i = 1; i <= K; i++) {
//             traverse(idx + 1, left - i);
//         }
//     }
// };

int main() {
    cout << Solution().numRollsToTarget(30, 30, 500);
}
