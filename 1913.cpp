#include "header.h"

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
	// the problem sets nums[i] > 0
	sort(nums.begin(), nums.end());
	return nums[nums.size() - 1] * nums[nums.size() - 2] - nums[0] * nums[1];	
    }
};

int main() {
    
}
