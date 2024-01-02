#include "header.h"

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int idx = 0;
        int ans = 0;
        for (auto& elem : g) {
            while (idx < s.size() && elem > s[idx])
                idx++;
            if (idx != s.size()) {
                ans++;
                idx++;
            }
        }
        return ans;
    }
};

int main() {

}
