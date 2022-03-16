#include <iostream>
#include "d_tnodel.h"
#include "d_tnode.h"

using namespace std;

template <typename T>
tnode<int> buildIntTree(){
        tnode<int> *f = new tnode<int> (12);
        tnode<int> *e = new tnode<int> (48);
        tnode<int> *d = new tnode<int> (5);
        tnode<int> *c = new tnode<int> (15, e, f);
        tnode<int> *b = new tnode<int> (40, d, (tnode<int> *)NULL);
        tnode<int> *root = new tnode<int> (35, b, c);

        return root;
    }

template <typename T>
int findMax(tnode<T> *t, int& max){
    if(t != NULL){
        if(max > t->nodeValue){
            findMax(t->left, max);
            findMax(t->right, max);
        }
        else if(max == t->nodeValue){
            findMax(t->left, max);
            findMax(t->right, max);
        }
        else if(max < t->nodeValue){
            max = t->nodeValue;
            findMax(t->left, max);
            findMax(t->right, max);
        }
    }
    return max;
}
