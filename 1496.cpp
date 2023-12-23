#include "header.h"

class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> s;
        s.insert(make_pair(0, 0));
        int idx_x = 0;
        int idx_y = 0;
        for (auto& elem : path) {
            switch (elem) {
            case 'N':
                idx_y++;
                break;
            case 'E':
                idx_x++;
                break;
            case 'W':
                idx_x--;
                break;
            case 'S':
                idx_y--;
                break;
            default:
                break;
            }
            if (s.count(make_pair(idx_x, idx_y))) {
                return true;
            }
            s.insert(make_pair(idx_x, idx_y));
        }
        return false;
    }
};

int main() {
    Solution().isPathCrossing("NES");
}