#include "header.h"

class Solution {
    struct point {
        int x;
        int y;
    };
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        point pre = { points[0][0], points[0][1] };
        for (int i = 1; i < points.size(); i++) {
            point cur = { points[i][0], points[i][1] };
            int offset_x = abs(cur.x - pre.x);
            int offset_y = abs(cur.y - pre.y);
            ans += min(offset_x, offset_y);
            ans += offset_x + offset_y - 2 * min(offset_x, offset_y);
            pre = cur;
        }
        return ans;
    }
};

int main() {

}