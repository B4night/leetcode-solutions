#include "header.h"

class Solution {
    int mod = 1e9 + 7;
    int dp[1005];
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int ans = 0;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] != 0) {
                    continue;
                }
                int div = arr[i] / arr[j];
                auto iter = find(arr.begin(), arr.end(), div);
                if (iter == arr.end())
                    continue;
                dp[i] += dp[j] * dp[iter - arr.begin()];
                dp[i] %= mod;
            }
            ans += dp[i];
            ans %= mod;
        }
        return ans;
    }
};

int main() {
    vector<int> v = {18,3,6,2};
    cout << Solution().numFactoredBinaryTrees(v);
    return 0;
}