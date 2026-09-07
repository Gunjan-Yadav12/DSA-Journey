#include<bits/stdc++.h>
using namespace std;

//factorial
// int factorial(int n){
//     //base case 
//     if(n == 0) return 1;      
//     int small = factorial(n-1);
//     int big = n * small;
//     return big;
// }
// int main(){
//     int n;
//     cin >> n;
//     int ans = factorial(n);
//     cout << ans << endl;
//     return 0;
// }

//pow(n)
// int power(int n){
//     //base case
//     if(n == 0) return 1;
//     int small = power(n-1);
//     int big = 2*small;
//     return big;
// }
// int main(){
//     int n;
//     cin >> n;
//     int ans = power(n);
//     cout << ans << endl;
//     return 0;
// }

//print counting
// void countPrint(int n){
//     if(n == 0) return ; //base case
//     countPrint(n-1); //recursive relation
//     cout << n << endl; //processing
// }
// int main(){
//     int n;
//     cin >> n;
//     countPrint(n);
//     return 0;
// }

//src dest example
// void reachHome(int src , int dest){
//     //visible 
//     cout << "Source " << src << " Destination " << dest << endl;  
//     //base case
//     if(src == dest){
//         cout << "reached " << endl;
//         return;
//     }
//     //processing
//     src++;
//     //recursive call
//     reachHome(src , dest);
// }
// int main(){
//     int dest = 10;
//     int src = 1;
//     cout << endl;
//     reachHome(src , dest);
//     return 0;
// }

//fibonacci series
// int  fibonacci(int n){
//     //base case
//     if(n == 0 ) return 0;
//     if( n == 1) return 1;
//     //recursive relation
//    int ans = fibonacci(n-1) + fibonacci(n-2);
//    return ans;
// }
// int main(){
//     int n = 8;
//     cout << fibonacci(n) << endl;
//     return 0;
// }

//fibonacci using for loop
// int fibonacci2(int n){
//     //base case 
//     if( n == 0) return 0;
//     if(n == 1) return 1;
//     //recursive relation using for loop
//     for(int i = 2; i <= n; i++){
//         return fibonacci2(n-1) + fibonacci2(n-2);
//     }
// }
// int main(){
//     int n = 5;
//     cout << fibonacci2(n) << endl;
//     return 0;
// }

//say digit
// void sayDigit(int n , string arr[]){
//     //base case
//     if(n == 0) return;
//     //proceesing
//     int digit = n % 10;
//     n = n / 10;
//     //recursive call 
//     sayDigit(n , arr);
//     cout << arr[digit] << " ";
// }
// int main(){
//      string arr[10] = {"Zero","One","Two","Three","Four",
//                     "Five","Six","Seven","Eight","Nine"};
//     int n;
//     cin >> n;
//     sayDigit(n , arr);
//     cout << endl;
//     return 0;
// }

//array is sorted or not (binary search using rec)
// bool isSorted(int arr[] , int size){
//     //base case
//     if(size == 0 || size == 1) return true;
//     if(arr[0] > arr[1]) return false;
//     else{
//         bool ans = isSorted(arr + 1 , size - 1);
//         return ans;
//     }
// }
// int main(){
//     int size;
//     cout << "Enter the size of the array: ";
//     cin >>  size;
//     int arr[size];
//     for(int i = 0; i < size; i++){
//         cin >> arr[i];
//     }
//     int ans = isSorted(arr , size);
//     cout << ans << endl;
//     return 0;
// }

//sum or array using rec
// int sum(int arr[] , int n){
//     //base case
//     if( n == 0) return 0;
//     if( n == 1) return arr[0];
//     //recursive call
//     int remainingPart = sum(arr + 1, n - 1);
//     int sum = arr[0] + remainingPart;
//     return sum;
// }
// int main(){
//     int n;
//     cout << "Enter the size of array: ";
//     cin >> n;
//     int arr[n];
//     cout << "Enter the elements of array: ";
//     for(int  i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     int getSum = sum(arr , n);
//     cout << "Sum is: " << getSum << endl;
//     return 0;
// }

//linear search using recursion
// void printArray(int arr[], int size){
//     cout << "Size of array is: " << size << endl;
//     for(int i = 0; i< size; i++){
//         cout << arr[i] << " ";
//     }cout << endl;
// }
// bool linearSearch(int arr[] , int size , int key){
//     printArray(arr , size);
//     //base case
//     if(size == 0) return false;
//     //processing
//     if(arr[0] == key) return true;
//     else{
//         //recusrive relation
//         bool remainingPart = linearSearch(arr + 1 , size - 1, key);
//         return remainingPart;
//     }
// }
// int main(){
//     int size;
//     cout << "Enter the size of the array: ";
//     cin >> size;
//     int arr[size];
//     cout << "Enter the elements of the array: ";
//     for(int i = 0; i < size; i++){
//         cin >> arr[i];
//     }
//     int key;
//     cout << "Enter the key to search: ";
//     cin >> key;
//     bool ans = linearSearch(arr , size , key);
//     cout << "Key found: " << ans << endl;
//     return 0;
// }

//binary search(recursion)
// bool binarySearch(int arr[] , int low ,int high , int key){
//     //base case
//     if(low > high) return false;
//     int mid = (low + high)/2;
//     //processing
//     if(arr[mid] == key) return true;
//     if(arr[mid] < key){
//         return binarySearch(arr , mid + 1, high , key);
//     } 
//     else{
//         return binarySearch(arr , mid - 1, low , key);
//     }
// }
// int main(){
//     int size;
//     cout << "Enter the size of the array: ";
//     cin >> size;
//     int arr[size];
//     cout << "Enter the elements of the array: ";
//     for(int i = 0; i< size; i++){
//         cin >> arr[i];
//     }
//     int key;
//     cout << "Enter the key to search: ";
//     cin >> key;
//     bool ans = binarySearch(arr , 0 , size-1 , key);
//     cout << "Key found: " << ans << endl;
//     return 0;
// }

//reverse string(using 2 pointer approach)
// void reverseString(string &str , int start , int end){
//     //base case
//     if(start > end) return;
//     //processing 
//     swap(str[start] , str[end]);
//     start++;
//     end--;
//     //recursive call
//     reverseString(str , start , end);
// }
// int main(){
//     int stringLength;
//     cout << "Enter the length of the string: ";
//     cin >> stringLength;
//     string str;
//     cout << "Enter the string: ";
//     cin >> str;
//     reverseString(str ,  0 , stringLength - 1);
//     cout << "Reversed String: " << str << endl;
//     return 0;
// }

//reverse string(using 1 pointer approach)
// void reverseString(string &str , int start){
//     //base case
//     if(start > (str.size() - start - 1)) return;
//     //processing 
//     swap(str[start] , str[str.size() - start - 1]);
//     start++; 
//     //recursive call
//     reverseString(str , start);
// }
// int main(){
//     int stringLength;
//     cout << "Enter the length of the string: ";
//     cin >> stringLength;
//     string str;
//     cout << "Enter the string: ";
//     cin >> str;
//     reverseString(str ,  0);
//     cout << "Reversed String: " << str << endl;
//     return 0;
// }

//check palindrome
// bool checkPalindrome(string &str , int start , int end){
//     //base case
//     if(start > end)return true;
//     //processing
//     if(str[start] != str[end]) return false;
//     else{
//         //recursive call
//         return checkPalindrome(str , start +  1 , end - 1);
//     }
// }
// int main(){
//     int stringLength;
//     cout << "Enter the length of the string: ";
//     cin >> stringLength;
//     string str;
//     cout << "Enter the string: ";
//     cin >> str;
//     bool isPalindrome = checkPalindrome(str ,  0 , stringLength - 1);
//     cout << isPalindrome << endl;
//     return 0;
// }

//power(x, n)
// int power(int base , int exponent){
//     //base case
//     if(exponent == 0) return 1;
//     if(exponent == 1) return base;
//     //recursive call
//     int half = power(base , exponent/2 );
//     //processing
//     int ans = (half * half);
//     if(exponent % 2 == 1) {
//         ans = (ans * base);
//     }
//     return ans;
// }
// int main(){
//     int base , exponent;
//     cout << "Enter base: ";
//     cin >> base;
//     cout << "Enter exponent: ";
//     cin >> exponent;
//     cout << "Power is: " << power(base , exponent) << endl;
//     return 0;
// }

//bubble sort using recursion
// void sortArray(int arr[] , int size){
//     //basecase
//     if(size == 0 || size == 1) return;
//     //processing
//     for(int  i = 0; i < size - 1; i++){
//         if(arr[i] > arr[i+1]){
//             swap(arr[i] , arr[i+1]);
//         }
//     }
//     //recursive call
//     sortArray(arr , size - 1);
// }
// int main(){
//     int n;
//     cout <<"Enter the size of array: ";
//     cin >> n;
//     int arr[n];
//     cout << "Enter the elements: ";
//     for(int i = 0; i< n; i++){
//         cin >> arr[i];
//     }
//     sortArray(arr , n);
//     cout << "Sorted Array: ";
//     for(int i = 0; i<n; i++){
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

//merge sort using recursion
// void merge(int arr[] , int start , int end){
//     int mid = (start + end)/2;
//     //lenght of 2 new arrays
//     int arr1 = mid - start + 1;
//     int arr2 = end - mid;
//     //create 2 new arrays
//     int *first = new int[arr1];
//     int *second = new int[arr2];
//     //copying values in new arrays
//     int mainArrayIndex = start;
//     for(int i = 0; i< arr1; i++){
//         first[i] = arr[mainArrayIndex++];
//     }
//     mainArrayIndex = mid + 1;
//     for(int i = 0; i< arr2; i++){
//         second[i] = arr[mainArrayIndex++];
//     }
//     //merge 2 sorted arrays
//     int index1 = 0;
//     int index2 = 0;
//     mainArrayIndex = start;
//     while(index1 < arr1 && index2 < arr2){
//         if(first[index1] < second[index2]){
//             arr[mainArrayIndex++] = first[index1++];
//         }
//         else{
//             arr[mainArrayIndex++] = second[index2++];
//         }
//     }
//     while(index1 < arr1){
//         arr[mainArrayIndex++] = first[index1++];
//     }
//     while(index2 < arr2){
//         arr[mainArrayIndex++] = second[index2++];
//     }
// }
// void mergeSort(int arr[] , int start , int end){
//     //base case
//     if(start >= end) return;
//     //processing
//     int mid = (start + end)/2;
//     //recursive call
//     mergeSort(arr , start , mid);
//     mergeSort(arr , mid + 1 , end);
//     //merge two sorted arrays
//     merge(arr , start , end);
// }
// int main(){
//     int n;
//     cout << "Enter the size of array: ";
//     cin >> n;
//     int arr[n];
//     cout << "Enter the elements: ";
//     for(int i = 0; i< n; i++){
//         cin >> arr[i];
//     }
//     mergeSort(arr , 0 , n-1);
//     cout << "Sorted Array: ";
//     for(int i = 0; i< n; i++){
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

//insertion sort using recursion
// void insertionSort(int arr[], int size){
//     //base case
//     if(size <= 1) return;
//     //recursive call
//     insertionSort(arr , size - 1);
//     //processing
//     for(int i = 0; i < size; i++){
//         int j = i;
//         while( j > 0 && arr[j-1] > arr[j]){
//             swap(arr[j-1] , arr[j]);
//             j--;
//         }
//     }
// }
// int main(){
//     int size;
//     cout << "Enter the size of the array: ";
//     cin >> size;
//     int arr[size];
//     cout << "Enter the elements of the array: ";
//     for(int i = 0; i < size; i++){
//         cin >> arr[i];
//     }
//     insertionSort(arr , size);
//     cout << "Sorted array: "  <<  endl;  
//     for(int i = 0; i < size; i++){
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

//Quick sort using recursion
// int partition(int arr[] , int start , int end){
//    int pivot = arr[start];
//    int count  = 0;
//    for(int i = start + 1; i <= end; i++){
//     if(arr[i] <= pivot) count++;
//    }
//    //right position of pivot
//    int pivotIndex = start + count;
//    swap(arr[pivotIndex] , arr[start]);
//     //left and right part sorting
//     int i = start , j = end;
//     while (i < pivotIndex && j > pivotIndex){
//         while(arr[i] <= pivot ) i++;
//         while(arr[j] > pivot) j--;
//         if(i < pivotIndex && j > pivotIndex){
//             swap(arr[i++] , arr[j--]);
//         }
//     }
//     return pivotIndex;
// }
// void quickSort(int arr[] , int start, int end){
//     //base case
//     if(start >= end) return;
//     //processing
//     int p = partition(arr , start , end);
//     //recursive call
//     quickSort(arr , start , p - 1);
//     quickSort(arr, p + 1 , end);
// }
// int main(){
//     int size;
//     cout << "Enter the size of the array: ";
//     cin >> size;
//     int arr[size];
//     cout << "Enter the elements of the array: ";
//     for(int i = 0; i < size; i++){
//         cin >> arr[i];
//     }
//     quickSort(arr , 0 , size -1);
//     cout << "Sorted array: " << endl;
//     for(int i = 0; i< size; i++){
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

