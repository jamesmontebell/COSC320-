#include <iostream>
#include "isPal.h"

using namespace std;

int main()
{
    string input;

    cout << "Enter a word: " << endl;
    cin >> input;
    if(isPal(input, 0, input.length()-1)){
        cout << "Is it a palindrome?: Yes" << endl; 
    }
    else{
        cout << "Is it a palindrome?: No" << endl;
    }
}