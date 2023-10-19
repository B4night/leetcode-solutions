#include "header.h"

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        char arr1[205];
        char arr2[205];
        int idx1 = 0;
        int idx2 = 0;

        for (auto& elem : s) {
            if (elem == '#') {
                idx1 = max(idx1 - 1, 0);
            } else {
                arr1[idx1] = elem;
                idx1++;
            }
        }

        for (auto& elem : t) {
            if (elem == '#') {
                idx2 = max(idx2 - 1, 0);
            } else {
                arr2[idx2] = elem;
                idx2++;
            }
        }

        if (idx1 != idx2) {
            return false;
        }

        for (int i = 0; i < idx1; i++) {
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    string s = "ab#c";
    string t = "ad#c";
    cout << Solution().backspaceCompare(s, t);
}