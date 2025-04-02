#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;

struct Quadruple {
    string op, arg1, arg2, result;
};

vector<Quadruple> quadruples;
int tempVarCount = 1;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string newTempVar() {
    return "t" + to_string(tempVarCount++);
}

void processOperator(stack<string> &operands, stack<char> &operators) {
    string right = operands.top(); operands.pop();
    string left = operands.top(); operands.pop();
    char op = operators.top(); operators.pop();
    
    string temp = newTempVar();
    quadruples.push_back({string(1, op), left, right, temp});
    operands.push(temp);
}

string infixToPostfix(string expr) {
    stack<char> operators;
    string postfix;
    
    for (size_t i = 0; i < expr.length(); i++) {
        if (isspace(expr[i])) continue;
        
        if (isdigit(expr[i])) {
            while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.')) {
                postfix += expr[i];
                i++;
            }
            postfix += ' ';
            i--;
        }
        else if (expr[i] == '(') {
            operators.push(expr[i]);
        }
        else if (expr[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.pop();
        }
        else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expr[i])) {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.push(expr[i]);
        }
    }
    
    while (!operators.empty()) {
        postfix += operators.top();
        postfix += ' ';
        operators.pop();
    }
    return postfix;
}

void generateQuadruples(string expr) {
    stack<string> operands;
    stack<char> operators;
    
    for (size_t i = 0; i < expr.length(); i++) {
        if (isspace(expr[i])) continue;
        
        if (isdigit(expr[i])) {
            string num;
            while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.')) {
                num += expr[i];
                i++;
            }
            i--;
            operands.push(num);
        }
        else if (expr[i] == '(') {
            operators.push(expr[i]);
        }
        else if (expr[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                processOperator(operands, operators);
            }
            operators.pop();
        }
        else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expr[i])) {
                processOperator(operands, operators);
            }
            operators.push(expr[i]);
        }
    }
    
    while (!operators.empty()) {
        processOperator(operands, operators);
    }
}

void printQuadruples() {
    cout << "Operator\tOperand1\tOperand2\tResult" << endl;
    for (const auto &quad : quadruples) {
        cout << quad.op << "\t\t" << quad.arg1 << "\t\t" << quad.arg2 << "\t\t" << quad.result << endl;
    }
}

int main() {
    string expr;
    cout << "Enter an arithmetic expression: ";
    getline(cin, expr);
    
    string postfix = infixToPostfix(expr);
    cout << "Postfix Expression: " << postfix << endl;
    
    generateQuadruples(expr);
    printQuadruples();
    
    return 0;
}
