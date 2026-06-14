/*
Problem: 3Sum Closest
Platform: LeetCode
problem number: 16

Approach:
1. Sort the array.
2. Fix one element at a time.
3. Use two pointers:
   - left = i + 1
   - right = n - 1
4. Calculate the current triplet sum.
5. Compare its distance from the target with
   the best answer found so far.
6. Update the closest sum if the current sum
   is closer to the target.
7. If sum < target:
      move left pointer
   If sum > target:
      move right pointer
   If sum == target:
      return immediately because an exact
      match cannot be improved.

Key Idea:
We do not care about the actual sum.

We care about:

|sum - target|

The smaller this value,
the closer the sum is to the target.

Example:

nums = [-1, 2, 1, -4]
target = 1

Sorted:
[-4, -1, 1, 2]

Initial:
closestSum = -4 + (-1) + 1 = -4

i = 0

sum = -4 + (-1) + 2 = -3

Distance:
|-3 - 1| = 4

Move left

sum = -4 + 1 + 2 = -1

Distance:
|-1 - 1| = 2

Update closestSum = -1

i = 1

sum = -1 + 1 + 2 = 2

Distance:
|2 - 1| = 1

Update closestSum = 2

Answer = 2

Pattern:
Sorting
Two Pointers

Time Complexity: O(n²)

Space Complexity: O(1)
(excluding sorting implementation)

Why abs()?

abs(sum - target)

gives the distance from the target.

Example:

target = 10

sum = 7
distance = |7 - 10| = 3

sum = 12
distance = |12 - 10| = 2

Since 2 < 3,
12 is closer to the target.

Revision:

1. Sort array.
2. Fix one element.
3. Two pointers.
4. Compare:

   abs(sum - target)

5. Store closest sum.
6. Exact match => return.
*/





class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closestSum = {nums[0] + nums[1] + nums[2]};
        sort(nums.begin() , nums.end());

        for(int i = 0; i < n;i++){

            int left = i + 1;
            int right  = n - 1;

            while(left < right){
                int sum = {nums[i] + nums[left] + nums[right]};
                
                if(abs(sum - target) < abs(closestSum - target)){
                    closestSum = sum;
                }
                if(sum < target) left++;
                else if(sum > target) right--;
                else {
                    return sum;
                }
              

            }
        }
        return closestSum;


    }
};