/*
Problem: Merge Intervals
Platform: LeetCode

Approach:
1. Sort all intervals based on their start time.
2. Create an answer array.
3. Traverse each interval:
   - If there is no overlap with the last
     interval in the answer array,
     add the current interval.
   - Otherwise, merge them by extending
     the ending point.
4. Continue until all intervals are processed.

Key Idea:
After sorting, overlapping intervals
become adjacent.

So we only need to compare the current
interval with the last merged interval.

Example:

Intervals:

[1,3]
[2,6]
[8,10]
[15,18]

After Sorting:

[1,3]
[2,6]
[8,10]
[15,18]

Process:

[1,3]

[2,6]

Overlap:

3 >= 2

Merge:

[1,6]

Current Answer:

[1,6]

Next:

[8,10]

No overlap:

6 < 8

Add it.

Answer:

[1,6]
[8,10]

Next:

[15,18]

No overlap:

10 < 15

Add it.

Final Answer:

[1,6]
[8,10]
[15,18]

Pattern:
Intervals
Sorting

Time Complexity:
O(n log n)

Sorting -> O(n log n)
Traversal -> O(n)

Space Complexity:
O(n)

Why Does Overlap Exist?

Two intervals overlap if:

currentStart <= previousEnd

Example:

[1,5]
[4,8]

Since:

4 <= 5

They overlap.

Merged Interval:

[1,8]

Revision:

Sort intervals

If:

ans.back().end < current.start

No overlap
Push interval

Else

Merge:

ans.back().end =
max(ans.back().end,
    current.end)
*/



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end());
         vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            
            if(ans.empty() || ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(intervals[i][1] , ans.back()[1]);
            }
        }
        return ans;
    }
};