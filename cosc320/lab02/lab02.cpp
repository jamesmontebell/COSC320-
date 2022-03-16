#include <iostream>
#include <random>
using namespace std;
#include "binSearch.h"
#include "deSelsort.h"

int main()
{
    int sumFailCom = 0;

    int successTotal = 0;

    srand(time(NULL));

    int arr[10000];

    int x = 0;

    for (int i = 0; i < 10000; i++)
    {
        arr[i] = rand() % 99999;
    }
    deSelsort(arr, 10000);
    for (int j = 0; j <= 10000; j++)
    {
        
        int x = rand() % 99999;

        if (binSearch(arr, 0, 10000, x, sumFailCom) != -1)
        {
            successTotal++;
        }
    }

    cout << "Fail count: "
         << "" << sumFailCom << endl;

    cout << "Success count: "
         << "" << successTotal << endl;

    int empirical = sumFailCom/(10000-successTotal);

    cout << "Empirical result: " << "" << empirical << endl;

    return 0;
}
