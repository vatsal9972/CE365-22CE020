#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int numSymbols;
    cout << "Enter number of input symbols: ";
    cin >> numSymbols;

    vector<char> symbols(numSymbols);
    map<char, int> symbolIndex;
    cout << "Enter the input symbols: " << endl;
    for (int i = 0; i < numSymbols; ++i) {
        cin >> symbols[i];
        symbolIndex[symbols[i]] = i; 
    }

    int numStates;
    cout << "Enter number of states: ";
    cin >> numStates;

    int initialState;
    cout << "Enter the initial state: ";
    cin >> initialState;

    int numAcceptingStates;
    cout << "Enter number of accepting states: ";
    cin >> numAcceptingStates;
    
    vector<int> acceptingStates(numAcceptingStates);
    cout << "Enter the accepting states: " << endl;
    for (int i = 0; i < numAcceptingStates; ++i) {
        cin >> acceptingStates[i];
    }
    
    vector<vector<int>> transition(numStates, vector<int>(numSymbols, -1));
    cout << "Enter transition table:" << endl;
    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numSymbols; j++) {
            cout << "Enter transition from state " << (i + 1) << " using symbol " << symbols[j] << ": ";
            cin >> transition[i][j];
        }
    }
    
    string inputString;
    cout << "Enter the input string: ";
    cin >> inputString;

    int currentState = initialState;
    for (char c : inputString) {
        if (symbolIndex.find(c) == symbolIndex.end()) {
            cout << "Invalid String" << endl;
            return 0;
        }
        int symbolPos = symbolIndex[c];
        currentState = transition[currentState - 1][symbolPos];
        if (currentState == -1) {
            cout << "Invalid String" << endl;
            return 0;
        }
    }
    
    for (int state : acceptingStates) {
        if (currentState == state) {
            cout << "Valid String" << endl;
            return 0;
        }
    }
    cout << "Invalid String" << endl;
    return 0;
}
