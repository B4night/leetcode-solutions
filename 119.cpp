#include "header.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        std::vector<int> ans;
        int dp[35][35];
        dp[0][0] = 1;
        dp[1][0] = 1;
        dp[1][1] = 1;
        for (int i = 2; i <= rowIndex; i++) {
            dp[i][0] = 1;
            for (int j = 1; j < i; j++) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            dp[i][i] = 1;
        }      
        
        ans.push_back(1);
        if (rowIndex == 0) {
            return ans;
        }
        for (int j = 1; j < rowIndex; j++) {
            ans.push_back(dp[rowIndex - 1][j - 1] + dp[rowIndex - 1][j]);
        }
        ans.push_back(1);
        return ans;
    }
};

int main() {
    Solution().getRow(3);
}