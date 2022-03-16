#include <iostream>
#include "d_tnodel.h"
#include "d_tnode.h"

using namespace std;

template <typename T>
void countOneChild(tnode<T> *t, int& count){
    if (t != NULL){
        if (t->left == NULL && t->right != NULL ||
         t->left != NULL && t->right == NULL){
             count++;
        }
        countOneChild(t->left, count);
        countOneChild(t->right, count);
    }
}