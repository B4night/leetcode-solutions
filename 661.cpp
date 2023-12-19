#include "header.h"

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // [i - 1, j - 1] -> [i + 1, j + 1]
                int cnt = 0;
                for (int a = max(i - 1, 0); a <= min(i + 1, m - 1); a++) {
                    for (int b = max(j - 1, 0); b <= min(j + 1, n - 1); b++) {
                        ans[i][j] += img[a][b];
                        cnt++;
                    }
                }
                ans[i][j] /= cnt;
            }
        }
        return ans;    
    }
};

int main() {

}