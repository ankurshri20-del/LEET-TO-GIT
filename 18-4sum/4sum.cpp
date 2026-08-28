class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;

        sort(nums.begin(), nums.end());  // Step 1: sort

        for (int a = 0; a < n - 3; a++) {
            // skip duplicate 'a' values
            if (a > 0 && nums[a] == nums[a - 1]) continue;

            for (int b = a + 1; b < n - 2; b++) {
                // skip duplicate 'b' values
                if (b > a + 1 && nums[b] == nums[b - 1]) continue;

                int left = b + 1;
                int right = n - 1;

                while (left < right) {
                    // use long long to avoid integer overflow
                    long long sum = (long long)nums[a] + nums[b] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[a], nums[b], nums[left], nums[right]});

                        // move both pointers inward, skipping duplicates
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    }
                    else if (sum < target) {
                        left++;   // sum too small, need a bigger number
                    }
                    else {
                        right--;  // sum too big, need a smaller number
                    }
                }
            }
        }

        return result;
    }
};