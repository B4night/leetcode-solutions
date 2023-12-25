#include "header.h"

// DFS:TLE
// class Solution {
//     int ans = 0;
// public:
//     bool valid(string& s, int startIdx, int endIdx) {
//         // s[startIdx, endIdx]
//         if (s[startIdx] == '0' || endIdx - startIdx >= 2)
//             return false;
//         // endIdx = startIdx or endIdx = startIdx + 1
//         if (endIdx == startIdx)
//             return true;
//         // endIdx = startIdx + 1
//         int cnt = s[startIdx] - '0';
//         cnt *= 10;
//         cnt += s[endIdx] - '0';
//         return cnt <= 26;
//     }
//     int numDecodings(string s) {
//         traverse(s, 0);
//         return ans;
//     }
//     void traverse(string& s, int idx) {
//         if (idx == s.size()) {
//             ans++;
//             return;
//         }
//         if (valid(s, idx, idx)) {
//             traverse(s, idx + 1);
//         }
//         if (idx + 1 < s.size() && valid(s, idx, idx + 1)) {
//             traverse(s, idx + 2);
//         }
//     }
// };

class Solution {
    int dp[105];
public:
    bool valid(string& s, int startIdx, int endIdx) {
        // s[startIdx, endIdx]
        if (s[startIdx] == '0' || endIdx - startIdx >= 2)
            return false;
        // endIdx = startIdx or endIdx = startIdx + 1
        if (endIdx == startIdx)
            return true;
        // endIdx = startIdx + 1
        int cnt = s[startIdx] - '0';
        cnt *= 10;
        cnt += s[endIdx] - '0';
        return cnt <= 26;
    }
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        // preprocess, deal with '0'
        string processed_s;
        for (auto& elem: s) {
            if (elem == '0') {
                if (processed_s.back() > '2') {
                    return 0;
                }
                processed_s.pop_back();
                processed_s.push_back('@');
                continue;
            }
            processed_s.push_back(elem);
        }

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        if (processed_s[1] == '@')
            dp[1] = 1;
        else {
            dp[1] = 1;
            if (valid(processed_s, 0, 1)) {
                dp[1] = 2;
            }
        }

        for (int i = 2; i < processed_s.size(); i++) {
            dp[i] = dp[i - 1];
            if (processed_s[i] == '@') {
                continue;
            }
            if (processed_s[i - 1] != '@' && valid(processed_s, i - 1, i)) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[processed_s.size() - 1];
    }
};

int main() {
    Solution().numDecodings("12");
}