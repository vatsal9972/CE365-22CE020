#include <iostream>
#include <string>

using namespace std;

class RDParser {
    string input;
    int pos;

public:
    RDParser(string str) : input(str), pos(0) {}

    bool S() {
        if (match('a')) {
            return true;
        } else if (match('(')) {
            if (L() && match(')')) {
                return true;
            }
        }
        return false;
    }

    bool L() {
        if (S()) {
            return L_prime();
        }
        return false;
    }

    bool L_prime() {
        if (match(',')) {
            if (S()) {
                return L_prime();
            }
            return false;
        }
        return true;
    }

    bool match(char expected) {
        if (pos < input.length() && input[pos] == expected) {
            pos++;
            return true;
        }
        return false;
    }

    bool parse() {
        bool result = S();
        return result && pos == input.length();
    }
};

int main() {
    string userInput;
    cout << "Enter a string: ";
    cin >> userInput;
    RDParser parser(userInput);
    cout << (parser.parse() ? "Valid string" : "Invalid string") << endl;
    return 0;
}
