#include <bits/stdc++.h>
using namespace std;

/** Ideas:
 * Based on the requirements we can know that:
 * 1. This array has nums.length numbers
 * 2. All the number are unique
 * 3. max_num - min_num = nums.length - 1
 * 
 * Which give us the result that: the range of the number is [X, X + nums.length - 1]
 * 
 * Q: What de we need to do?
 * A: Try to find a range in which contains the most numbers. Then we replace numbers which are not in this 
 *    range with numbers that are in this range.
 * 
 * Suggest a range contains M numbers, than the result is nums.length - M(we have to replace numbers that are out of this range)
 * 
 * Note: The result have to sublet the number of duplicate numbers
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // deduplicate the array, ensure the `new_arr` contains unique elements
        auto new_arr = std::vector<int>(nums.begin(), unique(nums.begin(), nums.end()));
        
        // res stores the minimun number of operations
        int res = std::numeric_limits<int>::max();
        int length = nums.size();

        for (int i = 0; i < new_arr.size(); i++) {
            // range [new_arr[i], new_arr[i] + nums.length - 1]
            int upper = new_arr[i] + length - 1;

            // find the position of the first element which is bigger than upper
            auto it = std::upper_bound(new_arr.begin(), new_arr.end(), upper);
            
            // calculate the length of the range
            int dis = std::distance(new_arr.begin() + i, it);

            // dis is the length of the range, if we choose this range, we have to do (length - dis) operations
            res = std::min(res, length - dis);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {11,44,25,49,40,41,6,9,49,4,47,12,32,49,26,30,2,23,17};
    cout << Solution().minOperations(nums);
    return 0;
}