/*
Problem: 3Sum
Platform: LeetCode

Approach:
1. Sort the array.
2. Fix one element.
3. Use two pointers to find the remaining two elements.
4. Skip duplicates.

Time Complexity: O(n²)
Space Complexity: O(1) (excluding output)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0)
                    left++;

                else if (sum > 0)
                    right--;

                else {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }

        return ans;
    }
};