#include <iostream>
#include "d_tnodel.h"
#include "d_tnode.h"
#include "max.h"

using namespace std;

int main(){

    tnode<int> *f = new tnode<int> (12);
    tnode<int> *e = new tnode<int> (48);
    tnode<int> *d = new tnode<int> (5);
    tnode<int> *c = new tnode<int> (15, e, f);
    tnode<int> *b = new tnode<int> (40, d, (tnode<int> *)NULL);
    tnode<int> *root = new tnode<int> (35, b, c);
    
    int maxNum = 0;
    findMax(root, maxNum);
    cout << maxNum << endl;
    displayTree(root, 3);
}