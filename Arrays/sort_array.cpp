class Solution {
public:
void merge(vector<int>& nums , int start , int end){

    int mid = (start + end)/2;

    //length of 2 new arrays

    int nums1 = mid - start + 1;
    int nums2 = end - mid;

    //create 2 new arrays

    int *first = new int[nums1];
    int *second = new int[nums2];

    //copying values in new arrays

    int mainArrayIndex = start;
    for(int i = 0; i< nums1; i++){
        first[i] = nums[mainArrayIndex++];
    }
    mainArrayIndex = mid + 1;
    for(int i = 0; i< nums2; i++){
        second[i] = nums[mainArrayIndex++];
    }

    //merge 2 sorted arrays

    int index1 = 0;
    int index2 = 0;

    mainArrayIndex = start;

    while(index1 < nums1 && index2 < nums2){
        if(first[index1] < second[index2]){
            nums[mainArrayIndex++] = first[index1++];
        }
        else{
            nums[mainArrayIndex++] = second[index2++];
        }
    }

    while(index1 < nums1){
        nums[mainArrayIndex++] = first[index1++];
    }

    while(index2 < nums2){
        nums[mainArrayIndex++] = second[index2++];
    }
}
void mergeSort(vector<int>& nums , int start , int end){

    //base case
    if(start >= end) return;

    //processing
    int mid = (start + end)/2;

    //recursive call
    mergeSort(nums , start , mid);
    mergeSort(nums , mid + 1 , end);

    //merge two sorted arrays
    merge(nums , start , end);
}

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums , 0 , nums.size()-1);
        return nums;
    }
};