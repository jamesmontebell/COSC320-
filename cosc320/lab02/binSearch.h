
#include <iostream>
using namespace std;

int binSearch(int arr[], int low, int high, int x, int& sumFailcom)
{
    int tempFailCom = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }

        if (arr[mid] < x)
        {
            low = mid + 1;
            tempFailCom++;
        }

        else
            high = mid - 1;
            tempFailCom++;
    }
    sumFailcom = sumFailcom + tempFailCom;
    return -1;
}
