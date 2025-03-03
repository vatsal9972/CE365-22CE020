#include <iostream>
#include <string>

using namespace std;

string input;
int pos = 0;


bool S();
bool L();
bool L_D();

bool S() {
    if (input[pos] == '(') {  
        pos++;
        if (L()) {
            if (input[pos] == ')') {
                pos++;
                return true;
            }
        }
    } else if (input[pos] == 'a') {
        pos++;
        return true;
    }
    return false;
}

bool L() {
    if (S()) {
        return L_D();
    }
    return false;
}


bool L_D(){
    if(input[pos]==',')
    {
        pos++;
        if(S())
        {
            L_D();
        }
        return false;
    }
    return true;
}

int main() {
    cout << "Enter a string: ";
    cin >> input;  
    pos = 0;

    if (S() && pos == input.length()) {
        cout << "Valid string\n";
    } else {
        cout << "Invalid string\n";
    }

    return 0;
}
