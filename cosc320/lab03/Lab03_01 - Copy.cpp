#include <iostream>
#include "d_tnodel.h"
#include "d_tnode.h"
#include "countOneChild.h"

using namespace std;

int main(){
    int count = 0;
    tnode<char> *g = new tnode<char> ('G');
    tnode<char> *f = new tnode<char> ('F');
    tnode<char> *e = new tnode<char> ('E', (tnode<char> *)NULL, g);
    tnode<char> *d = new tnode<char> ('D');
    tnode<char> *c = new tnode<char> ('C', e, f);
    tnode<char> *b = new tnode<char> ('B', d, (tnode<char> *)NULL);
    tnode<char> *a = new tnode<char> ('A', b, c);

    countOneChild(a, count);
    cout << count << endl;
    displayTree(a, 3);
}