class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size() - 1;   // 1. Set up the search boundaries

        while (left <= right) {        // 2. Keep searching while there's a valid range
            
            int mid = (left + right) / 2;   // 3. Find the middle index

            if (nums[mid] == target) {      // 4. Found the target
                return mid;                 //    Return its index
            }

            else if (nums[mid] < target) {  // 5. Target is bigger
                left = mid + 1;             //    Search the right half
            }

            else {                          // 6. nums[mid] > target
                right = mid - 1;            //    Search the left half
            }
        }

        return left;    // 7. Target not found → insertion position
    }
};