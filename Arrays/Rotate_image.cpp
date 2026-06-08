/*
Problem: Rotate Image
Platform: LeetCode
Problem Number: 48

Brute force Approach:
1. Use an extra matrix to store the rotated result.
2. The element at position (i, j) moves to
   position (j, n - 1 - i).
3. Traverse the entire matrix and place each element
   in its rotated position.
4. Replace the original matrix with the rotated matrix.

Time Complexity: O(n^2)
Space Complexity: O(n^2) 

Optimal Approch:
1. Transpose the matrix by swapping matrix[i][j]
   with matrix[j][i].
2. Transposition converts rows into columns.
3. Reverse every row of the transposed matrix.
4. Reversing each row 1. Transpose the matrix by swapping matrix[i][j]
   with matrix[j][i].
2. Transposition converts rows into columns.
3. Reverse every row of the transposed matrix.
4. Reversing each row produces a 90-degree
   clockwise rotation.

   Time Complexity: O(n/2 * n/2)
   Space Complexity: O(n/2) 

*/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i <n-1; i++){
            for(int j=i+1;j<n;j++){

                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};