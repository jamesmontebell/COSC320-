#include <iostream>
 
using namespace std;

bool isPal(string str, int start, int end){
    if(start >= end){ //stopping condition
        return true;
    }
    if(str[start] != str[end]){ //stopping condition
        return false;
    }   
    return isPal(str, start+1, end-1); //recursion step

}