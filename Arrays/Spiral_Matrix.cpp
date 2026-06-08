/*
Problem: Spiral Matrix
Platform: LeetCode
Problem Number: 54

Approach:
1. Imagine the matrix has four walls:
   - Top
   - Bottom
   - Left
   - Right

2. Traverse the matrix layer by layer.

3. Follow this order:
   - Move left → right on the top row. --> top++
   - Move top → bottom on the right column. --> right--
   - Move right → left on the bottom row. --> bottom--
   - Move bottom → top on the left column. --> left++

4. After completing one layer,
   shrink the boundaries:
   - top++
   - right--
   - bottom--
   - left++

5. Repeat until all elements are visited.

Key Idea:
Keep shrinking the four boundaries after
traversing each outer layer of the matrix.
*/



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = n - 1;
        int top = 0, bottom = m - 1;
        vector<int>ans;

    while(top <=bottom && left <= right){

        for(int i = left; i <=right; i++){
            ans.push_back(matrix[top][i]);
        } 
        top++;
        for(int i = top; i <= bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top <= bottom){
            for(int i = right; i>=left; i--){
                ans.push_back(matrix[bottom][i]);
            }
        bottom--;
        }
        if(left <= right){
            for(int i = bottom; i>=top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        } 
    }
    return ans;
    }
};