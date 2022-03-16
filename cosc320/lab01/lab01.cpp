using namespace std;
#include <iostream>
#include "deSelsort.h"
#include <ctime>

int main()
{
    int arr[] = {13, 5, 2, 25, 47, 17, 8, 21};
    int newArr[] = {4, 14, 74, 24, 47, 4, 64, 44};
    int epicArr[] = {73, 7, 10, 69, 42, 56, 4, 21};
    deSelsort(arr, 8);
    deSelsort(newArr, 8);
    deSelsort(epicArr, 8);
    cout << endl;
    cout << "Sorted array: " << endl;
    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Sorted array: " << endl;
    for (int i = 0; i < 8; i++)
        cout << newArr[i] << " ";
    cout << endl;

    cout << "Sorted array: " << endl;
    for (int i = 0; i < 8; i++)
        cout << epicArr[i] << " ";
    cout << endl;

    return 0;
}
