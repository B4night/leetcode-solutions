#include "header.h"

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> s;
        for (auto& elem : points) {
            s.insert(elem[0]);
        }
        auto nxt_iter = s.begin();
        auto iter = nxt_iter++;
        int ans = *nxt_iter - *iter;
        while (nxt_iter != s.end()) {
            ans = max(ans, *nxt_iter - *iter);
            nxt_iter++;
            iter++;
        }
        return ans;
    }
};

int main() {

}