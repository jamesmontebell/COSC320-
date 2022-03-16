using namespace std;
#include <iostream>

void deSelsort(int *arr, int n)
{
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        // start min and max as the first element of the array.
        int min = arr[i], max = arr[i];
        // start index as the first element of the array.
        int min_idx = i, max_idx = i;
        // setting k to search from the front of the array
        // and stop iterating once it meets j which is iterating backwards.
        for (int k = i; k <= j; k++)
        {
            // if the index k in the array is greater than the current max
            // swap them.
            if (arr[k] > max)
            {
                max = arr[k];
                max_idx = k;
            }
            // if the index k in the array is less than the current min
            // swap them.
            else if (arr[k] < min)
            {
                min = arr[k];
                min_idx = k;
            }
        }
        // once it finds the new minimum number it swaps it to the front of the away.
        swap(arr[i], arr[min_idx]);

        // if the current minimum number in the array is equal to the current max
        // swap index j (working back to front) with current minimum.
        // Else if the current minimum number is less than the current max swap
        // index j with the newfound current max.
        if (arr[min_idx] == max)
            swap(arr[j], arr[min_idx]);
        else
            swap(arr[j], arr[max_idx]);

        // int *ptr = &arr[0];
        // cout << endl;
        // cout<<"Sorting unsorted array: " << endl;
        // for(int i = 0; i < 8; i++) {
        //     cout<< *ptr <<" ";
        //     ptr++;
    }
}
