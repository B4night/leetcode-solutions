#include "header.h"

class Solution {
int dp[3000];    
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main() {

}
