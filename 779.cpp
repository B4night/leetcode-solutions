#include "header.h"

/**
 * 1:  0
 * 2:  01
 * 4:  0110
 * 8:  01101001
 * 16: 0110 1001 1001 0110
 * 32: 0110 1001 1001 0110 1001 0110 0110 1001
 * 
*/

/**
 * 1. kth element can be generated from the ((k+1)/2)th element of the previous row
 * 2. recursivele calculate
*/

class Solution {
public:
    int kthGrammar(int n, int k) {
        return traverse(n, k);
    }
    // traverse(r, k) return the kth number in row r
    int traverse(int r, int k) {
        if (r == 1) { // boundary
            return 0;
        }
        int last_idx = (k + 1) / 2;     // the index of the row (r-1)
        int ret = traverse(r - 1, last_idx);  // get value from the row (r-1)
        // kth number is generated from the (last_idx)th number of the row (r-1)
        if (ret == 0) {     // generated from 0
            if (k & 0x1)    // test the parity of k
                return 0;
            return 1;
        }
        // generated from 1
        if (k & 0x1)        // test parity
            return 1;
        return 0;
    }
};

int main() {
    cout << Solution().kthGrammar(2, 3);
}