#include <iostream>
#include <utility>
#include <time.h>
#include "int.h"
#include "d_random.h"
#include "d_stree.h"
#include "d_except.h"

using namespace std;

int main()
{

    srand(time(0));

    stree<integer> integerTree;

    for (int i = 0; i < 10000; i++)
    {

        int temp = rand() % 7;

        stnode<integer> *findTemp = integerTree.findNode(temp);

        if (findTemp == NULL)
        {
            integerTree.insert(temp);
        }
        else
        {
            findTemp->nodeValue.incCount();
        }
    }

    stnode<integer> *tempNode;
    cout << "Display Nodes: " << endl;
    for(int j = 0; j < 7; j++){
        tempNode = integerTree.findNode(j);
        cout << tempNode->nodeValue << endl;
    }

    cout << "Display Tree: " << endl;
    integerTree.displayTree(1);
}

