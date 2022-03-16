using namespace std;
#include <iostream>

    int successTotal = 0;
    int sumFailCom = 0;

int binSearch(int arr[], int low, int high, int x ){
    int mid = (low + high)/2;
    if(low > high){
        return -1;
    }

    else
        if (x == arr[mid]){
            successTotal++; 
            return 0;
        }

        else if(x > arr[mid]){
            sumFailCom++;
            return binSearch(arr, mid + 1, high, x);
        }

        else if(x < arr[mid]){
            sumFailCom++;
            return binSearch(arr, low, mid - 1, x);
        }
}