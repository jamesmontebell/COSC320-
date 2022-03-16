
#include <set>
#include "d_state.h"
#include <iostream>


using namespace std;

int main(){
    miniSet<stateCity> s;
    s.insert(stateCity("Maryland", "Salisbury"));  
    s.insert(stateCity("Delaware", "Seaford"));
    s.insert(stateCity("Pennsylvania", "Pittsburgh"));
    s.insert(stateCity("Ohio", "Cleveland"));
    s.insert(stateCity("Michigan", "Detroit"));

    string input;

    cout << "Input the name of a state (case sensiteive): " << endl;
    cin >> input;
    
    if(s.find(input) != s.end()){
        
        cout << s.find(input) << endl;
    }
}