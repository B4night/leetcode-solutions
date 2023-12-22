#include "header.h"

class Solution {
public:
    int maxScore(string s) {
        // The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.
        int idx = 1;
        // split into [0, idx), [idx, s.size())
        int left_val = s[0] == '0' ? 1 : 0;
        int right_val = 0;
        int ans = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '1') 
                right_val++;
        }
        ans = left_val + right_val;

        for (; idx < s.size() - 1; idx++) {
            if (s[idx] == '0') {
                left_val++;
            } else {
                right_val--;
            }
            ans = max(ans, left_val + right_val);
        }
        return ans;
    }
};

int mai() {

}