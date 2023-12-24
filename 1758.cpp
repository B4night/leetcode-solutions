#include "header.h"

class Solution {
public:
    int minOperations(string s) {
        // either 0101 or 1010
        // check in 2 ways and find the minimum operation times.
        // 0101---
        int val1 = 0;   // cnt of operations for 0101---
        int val2 = 0;
        int flag = 0;
        for (auto& elem : s) {
            if (elem - '0' != flag)
                val1++;
            else
                val2++;
            flag = !flag;
        }
        return min(val1, val2);
    }
};

int main() {
    cout << Solution().minOperations("0100");
}