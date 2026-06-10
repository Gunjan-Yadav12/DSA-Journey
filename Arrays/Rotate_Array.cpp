/*
Problem: Rotate Array
Platform: LeetCode
Problem number: 189

Approach:
1. Calculate k % n because rotating n times
   brings the array back to its original position.
2. Store the last k elements in a temporary array.
3. Shift the remaining elements k positions to the right.
4. Copy the stored elements to the first k positions.

Key Idea:
Break the array into two parts:
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        vector<int>temp(k);

        for(int i=n-k; i<n; i++){
            temp[i-(n-k)] = nums[i];
        }
        for(int i= n-k-1; i>=0; i--){
            nums[i+k] = nums[i];
        }
        for(int i=0; i<k ; i++){
            nums[i] = temp[i];
        }
    }
};