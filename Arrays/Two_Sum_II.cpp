/*
Problem: Two Sum II - Input Array Is Sorted
Platform: LeetCode
problem number: 167

Approach:
1. Since the array is sorted,
   place two pointers:
   - left at the beginning
   - right at the end

2. Calculate:
      sum = numbers[left] + numbers[right]

3. If sum is smaller than target,
   move left pointer to increase the sum.

4. If sum is greater than target,
   move right pointer to decrease the sum.

5. If sum equals target,
   return the 1-based indices.

Key Idea:
Use the sorted property of the array.

Instead of checking every pair,
adjust the pointers intelligently.

Example:

numbers = [2,7,11,15]
target = 9

left = 0
right = 3

sum = 2 + 15 = 17

17 > 9

Move right

left = 0
right = 2

sum = 2 + 11 = 13

13 > 9

Move right

left = 0
right = 1

sum = 2 + 7 = 9

Found Answer

Return:
[1, 2]

Pattern:
Two Pointers
Sorted Array

Time Complexity: O(n)

Space Complexity: O(1)

Why Does It Work?

Because the array is sorted.

If:

sum < target

Moving right pointer left
would make the sum even smaller.

So the only useful move is:

left++

Similarly:

sum > target

Moving left pointer right
would make the sum larger.

So the only useful move is:

right--

Revision:

left = 0
right = n - 1

sum = numbers[left] + numbers[right]

sum < target:
    left++

sum > target:
    right--

sum == target:
    return answer
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        pair<int , int> ans;
        int right = n -1;
        int left = 0;

        while(left < right){

            int sum = {numbers[left] + numbers[right]};

            if(sum < target) left ++;
            else if(sum > target) right --;
            else{
                ans = { left + 1 , right + 1};
                right --;
                left ++;

                while(left < right && numbers[left] == numbers[left -1]) left++;
                while(left< right && numbers[right] == numbers[ right + 1]) right --;
            }
        }
        return {ans.first , ans.second};
        
    }
};