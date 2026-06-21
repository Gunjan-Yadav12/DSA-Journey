/)Main Logic:

Traverse from left → right and keep track of the maximum element seen so far.
If nums[i] < maxSeen, then i must belong to the unsorted subarray → update right.
Traverse from right → left and keep track of the minimum element seen so far.
If nums[i] > minSeen, then i must belong to the unsorted subarray → update left.
Length of required subarray = right - left + 1.
If no violation is found (right == -1), the array is already sorted → return 0.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int  n = nums.size();
        
        int left = -1;
        int right = -1;
        int maxElement = nums[0];
        int minElement = nums[n-1];

        for(int i =0;i<n;i++){
            if(nums[i] < maxElement) right = i;
            
            else maxElement = nums[i];
        }

            if(right == -1) return 0;

        for(int i=n-1;i>=0;i--){
            if(nums[i] > minElement) left = i;
            
            else minElement = nums[i];
        }

        return (right - left + 1);
    }
};