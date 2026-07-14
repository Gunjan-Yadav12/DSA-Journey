/*
Pattern:
Binary Search

Find First Occurrence:

Initialize:

low = 0
high = n - 1
first = -1

While:

low <= high

mid = low + (high - low) / 2

If:

arr[mid] == target

Store answer:

first = mid

Search Left:

high = mid - 1

Else If:

arr[mid] < target

Search Right:

low = mid + 1

Else:

Search Left:

high = mid - 1

--------------------------------

Find Last Occurrence:

Initialize:

low = 0
high = n - 1
last = -1

While:

low <= high

mid = low + (high - low) / 2

If:

arr[mid] == target

Store answer:

last = mid

Search Right:

low = mid + 1

Else If:

arr[mid] < target

Search Right:

low = mid + 1

Else:

Search Left:

high = mid - 1

--------------------------------

Count Occurrences:

If:

first == -1

Return 0

Else:

Count =

last - first + 1

Why does it work?

The first binary search
finds the leftmost occurrence
of the target.

The second binary search
finds the rightmost occurrence.

The number of occurrences
is simply the number of indices
between them.

Time: O(log n)

Space: O(1)
*/

class Solution {
public:
int firstOccurence(vector<int>& arr, int target){
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int first = -1;

        while(low <= high){
            int mid = (low + high)/2;

            if(arr[mid] == target){
                first = mid;
                high = mid - 1;
            }
            else if(arr[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return first;
    }
    int lastOccurence(vector<int>& arr, int target){
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int last = -1;

        while(low <= high){
            int mid = (low + high)/2;

            if(arr[mid] == target){
                last = mid;
                low = mid + 1;
            }
            else if(arr[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return last;

    }
    pair<int , int> searchRange(vector<int>& arr, int target) {
    
        int first = firstOccurence(arr , target);
        if(first == -1) return {-1 , -1};

        int last = lastOccurence(arr, target);
       return {first , last};
    }

    int countOccurrences(vector<int>& arr, int target) {
      
      pair<int , int> ans = searchRange( arr, target);

      if(ans.first == -1) return 0;

      return {ans.second - ans.first + 1};
    }
};