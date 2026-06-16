/*
Problem: Trapping Rain Water
Platform: LeetCode
problem number: 42

Approach:
1. Use two pointers:
   - left at the beginning
   - right at the end

2. Maintain:
   - leftMax = tallest wall seen from left
   - rightMax = tallest wall seen from right

3. At every step:
   - Update leftMax and rightMax.
   - Compare leftMax and rightMax.

4. If leftMax < rightMax:
   - Water at left depends only on leftMax.
   - Add:
       leftMax - height[left]
   - Move left pointer.

5. Otherwise:
   - Water at right depends only on rightMax.
   - Add:
       rightMax - height[right]
   - Move right pointer.

6. Continue until pointers meet.

Key Idea:
Water trapped at an index is:

min(leftMax, rightMax) - height[i]

The smaller boundary determines
the maximum water level.

Instead of storing leftMax and rightMax
for every index, use two pointers
and process the side with the smaller maximum.

Example:

height =
[4,2,0,3,2,5]

Water Above Each Index:

4 2 0 3 2 5
0 2 4 1 2 0

Total Water:

0 + 2 + 4 + 1 + 2 + 0 = 9

Pattern:
Two Pointers
Prefix Maximum Concept

Time Complexity: O(n)

Space Complexity: O(1)

Why Process Smaller Maximum?

Suppose:

leftMax = 4
rightMax = 8

Current:

4       8
|       |
|   ?   |
|_______|

The water level can never exceed 4
because the smaller wall limits it.

Therefore, we already know the answer
for the left side.

No need to know future walls.

Revision:

leftMax = max(leftMax, height[left])
rightMax = max(rightMax, height[right])

If leftMax < rightMax:

    water += leftMax - height[left]
    left++

Else:

    water += rightMax - height[right]
    right--

Formula:

Water =
min(leftMax, rightMax)
-
height[i]
*/




class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;

        int left = 0;
        int right = n - 1;

        int rightMax = 0;
        int leftMax = 0;

        while(left < right){

            leftMax = max(leftMax , height[left]);
            rightMax = max(rightMax,  height[right]);

            if(leftMax < rightMax){

                totalWater += (leftMax - height[left]);
                left++;
            }
            else{

                totalWater += (rightMax - height[right]);
                right--;
            }

        }
        return totalWater;
    }
};