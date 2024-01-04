#include "header.h"

class Solution {
    int dp[100005];
public:
    int minOperations(vector<int>& nums) {
        map<int, int> m;
        int max_val = INT_MIN;
        for (auto& elem : nums) {
            m[elem]++;
        }
        for (auto& elem : m) {
            if (elem.second == 1) {
                return -1;
            }
            max_val = max(max_val, elem.second);
        }
        
        calculate_dp(max_val);

        int ans = 0;
        for (auto& elem : m) {
            ans += dp[elem.second];
        }
        return ans;
    }
    void calculate_dp(int max_val) {
        memset(dp, 0, sizeof(dp));
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        for (int i = 5; i <= max_val; i++) {
            dp[i] = min(dp[i - 2], dp[i - 3]) + 1;
        }
    }
};

int main() {
    vector<int> v = {14,12,14,14,12,14,14,12,12,12,12,14,14,12,14,14,14,12,12};
    Solution().minOperations(v);
}