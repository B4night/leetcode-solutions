#include "header.h"

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int idx = 0;
        int ans = 0;
        while (idx < colors.size() - 1) {
            int lstIdx = idx + 1;
            if (colors[lstIdx] != colors[idx]) {
                idx++;
                continue;
            }
            int sum = neededTime[idx];
            int maxVal = sum;
            while (lstIdx < colors.size() && colors[lstIdx] == colors[idx]) {
                sum += neededTime[lstIdx];
                maxVal = max(maxVal, neededTime[lstIdx]);
                lstIdx++;
            }
            ans += sum - maxVal;
            idx = lstIdx;
        }
        return ans;
    }
};

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    Solution().minCost("abaac", v);
}