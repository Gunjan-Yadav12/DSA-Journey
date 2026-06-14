/*
Problem: Container With Most Water
Platform: LeetCode

Approach:
1. Place two pointers:
   - Left at the beginning.
   - Right at the end.

2. Calculate the area formed by the two lines.

3. The water level is limited by the
   shorter line.

   Area =
   Width × Minimum Height

4. Update the maximum area found so far.

5. Move the pointer having the smaller height.
   Because moving the taller line can never
   increase the water level.

6. Repeat until both pointers meet.

Key Idea:
The shorter line is always the bottleneck.

To get a larger area, we need a chance
to find a taller shorter line.

Therefore:
Move the smaller height pointer.

Example:

height = [1,8,6,2,5,4,8,3,7]

left = 0 (1)
right = 8 (7)

Area = (8 - 0) × min(1,7)
     = 8 × 1
     = 8

Since 1 < 7,
move left pointer.

left = 1 (8)
right = 8 (7)

Area = (8 - 1) × min(8,7)
     = 7 × 7
     = 49

Maximum Area = 49

Pattern:
Two Pointers
Greedy

Time Complexity: O(n)

Space Complexity: O(1)

Why Move Smaller Height?

Suppose:

left = 3
right = 10

Heights:

3      10
|       |
|       |
|   |   |
|___|___|

Water level is determined by
the shorter line.

Moving the taller line inward:

- Width decreases.
- Height does not improve.

Area can only decrease.

Moving the shorter line:

- Width decreases.
- But we may find a taller line.

This is the only chance of getting
a larger area.

Revision:

Area =
(right - left)
*
min(height[left], height[right])

Move:
Smaller Height Pointer

Track:
Maximum Area
*/



class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int maxArea = 0;

        while(left < right){
            int area = (right - left) * min(height[right] , height[left]);
           
           if(height[left] < height[right]) left ++;
           else right --;

           maxArea = max(area, maxArea);
        }
        return maxArea;

    }
};
 