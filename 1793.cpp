#include "header.h"

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        // i <= k <= j
        int leftIdx;        // i
        int rightIdx;       // j
        leftIdx = rightIdx = k; // start at k
        int sum = nums[k];      // answer
        int minVal = nums[k];   // min val of the range  
        while (leftIdx > 0 || rightIdx < nums.size() - 1) {
            int move = 0;       // a flag of whether have a good movement

            // 2 good movements below
            if (leftIdx > 0) {
                if (nums[leftIdx - 1] >= minVal) {  
                    leftIdx -= 1;
                    sum = max(sum, minVal * (rightIdx - leftIdx + 1));
                    move = 1;
                }
            }
            if (rightIdx < nums.size() - 1) {
                if (nums[rightIdx + 1] >= minVal) {
                    rightIdx += 1;
                    sum = max(sum, minVal * (rightIdx - leftIdx + 1));
                    move = 1;
                }
            }

            // now we have to force to move, move to where loss is minimum
            if (!move) {
                if (leftIdx == 0) { // this statement is true means we have to move the right side
                    rightIdx += 1;
                    minVal = min(nums[rightIdx], minVal);
                    sum = max(sum, minVal * (rightIdx - leftIdx + 1));
                } else if (rightIdx == nums.size() - 1) { // this statement is true means we have to move the left side
                    leftIdx -= 1;
                    minVal = min(nums[leftIdx], minVal);
                    sum = max(sum, minVal * (rightIdx - leftIdx + 1));
                } else {    // we can move both side, choose a side which has less loss
                    if (nums[leftIdx - 1] > nums[rightIdx + 1]) {
                        leftIdx -= 1;
                        minVal = min(nums[leftIdx], minVal);
                        sum = max(sum, minVal * (rightIdx - leftIdx + 1));
                    } else {
                        rightIdx += 1;
                        minVal = min(nums[rightIdx], minVal);
                        sum = max(sum, minVal * (rightIdx - leftIdx + 1));
                    }
                }
            }
        }
        return sum;
    }
};

int main() {
    vector<int> v = {5,5,4,5,4,1,1,1};
    int k = 0;
    cout << Solution().maximumScore(v, k);
}