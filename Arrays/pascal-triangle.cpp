/*
Problem: Pascal's Triangle
Platform: LeetCode
problem number: 118

Approach:
1. Generate each row independently.
2. The first element of every row is always 1.
3. Use the relation between consecutive elements:

   nCr = nC(r-1) * (n-r+1) / r

4. Starting from 1, compute the next element
   using the previous element instead of
   calculating factorials repeatedly.
5. Generate all rows from 1 to numRows.

Key Idea:
Each element can be derived from the previous
element in the same row.

Instead of:

nCr = n! / (r! * (n-r)!)

use:

next = previous * (n-r) / r

This avoids expensive factorial calculations.

Example:

Row 5:

1

1 * 4/1 = 4

4 * 3/2 = 6

6 * 2/3 = 4

4 * 1/4 = 1

Result:
[1, 4, 6, 4, 1]

Pascal's Triangle:

        1
      1   1
    1   2   1
  1   3   3   1
1   4   6   4   1

Pattern:
Math
Combinatorics

Time Complexity: O(n²)
Space Complexity: O(1) extra
(excluding output)

Revision:
1. First element = 1
2. Generate next element from previous
3. Use:

   next = previous * (row-col) / col

4. Build one row at a time
*/

class Solution {
public:
vector<int> generateRow(int row){
    long long ans = 1;
    vector<int>ansRow;
    ansRow.push_back(1);
    for(int col = 1; col < row; col++){
        ans = ans * (row - col);
        ans = ans /col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i = 1; i<= numRows; i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};