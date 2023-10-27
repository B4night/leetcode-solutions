#include "header.h"

class Solution {
public:
    string longestPalindrome(string s) {
        int pivot;
        int len = s.size();
        int ans = 0;
        int idx = -1;

        // seperate by parity
        // odd
        for (pivot = 0; pivot < len; pivot++) {
            int left = pivot - 1;
            int right = pivot + 1;
            int tmp = 1;
            while (left >= 0 && right < len) {
                if (s[left] == s[right]) {
                    left--;
                    right++;
                    tmp += 2;
                } else {
                    break;
                }
            }
            if (ans < tmp) {
                ans = tmp;
                idx = left + 1;
            }
        }

        // even
        for (pivot = 0; pivot < len - 1; pivot++) {
            int left = pivot;
            int right = pivot + 1;
            int tmp = 0;
            while (left >= 0 && right < len) {
                if (s[left] == s[right]) {
                    left--;
                    right++;
                    tmp += 2;
                } else {
                    break;
                }
            }
            if (ans < tmp) {
                ans = tmp;
                idx = left + 1;
            }
        }

        return s.substr(idx, ans);
    }
};

// cbbd
// dbbc

int main() {
    string s = "cbbd";
    cout << Solution().longestPalindrome(s);
}