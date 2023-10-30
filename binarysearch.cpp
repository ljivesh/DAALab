#include <iostream>
using namespace std;
 
// An iterative binary search function.
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // If we reach here, then element was not present
    return -1;
}
 
// Driver code
int main(void)
{
   cout<<"Palak Garg 35514811621\n";

    int arr[] = { 20, 32, 34, 100, 400 };
    int x = 34;
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout<<"Array is: ";
    for (int i=0; i<5; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element "<<x<<" is present at index " << result;
    return 0;
}
