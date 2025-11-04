#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

// Class for handling expression operations
class Expression {
public:
    // Function declarations
    bool isOperator(char x);     // Check if a character is an operator
    int precedence(char x);      // Return precedence of operator
    void prefix_infix();         // Convert Prefix to Infix
    void infix_postfix();        // Convert Infix to Postfix
    void prefix_eval();          // Evaluate Prefix expression
};

// Function to check if a given character is an operator
bool Expression::isOperator(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^');
}

// Function to define operator precedence
int Expression::precedence(char x) {
    if (x == '^') return 3;
    else if (x == '*' || x == '/') return 2;
    else if (x == '+' || x == '-') return 1;
    else return 0;
}

// Function to convert Prefix expression to Infix form
void Expression::prefix_infix() {
    string prefix;
    cout << "Enter Prefix Expression: ";
    cin >> prefix;

    stack<string> s;         // Stack for storing intermediate strings
    int len = prefix.length();

    // Scan prefix from right to left
    for (int i = len - 1; i >= 0; i--) {
        char c = prefix[i];

        // If character is operator, pop two operands and form an infix subexpression
        if (isOperator(c)) {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string temp = "(" + op1 + c + op2 + ")";
            s.push(temp);
        } 
        // If character is operand, push it as a string
        else {
            string operand(1, c);
            s.push(operand);
        }
    }

    // Final infix expression is on the top of the stack
    cout << "Infix Expression: " << s.top() << endl;
}

// Function to convert Infix expression to Postfix form
void Expression::infix_postfix() {
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;

    stack<char> s;           // Stack to store operators
    string postfix = "";     // Resultant postfix expression

    // Traverse the infix expression
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If operand (letter or digit), add to postfix output
        if (isalnum(c))
            postfix += c;

        // If opening bracket, push to stack
        else if (c == '(')
            s.push(c);

        // If closing bracket, pop until '('
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop(); // Pop the '('
        }

        // If operator, pop operators of higher or equal precedence first
        else {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop remaining operators
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix Expression: " << postfix << endl;
}

// Function to evaluate a Prefix expression (numeric)
void Expression::prefix_eval() {
    string prefix;
    cout << "Enter Prefix Expression (Operands as single digits): ";
    cin >> prefix;

    stack<int> s;
    int len = prefix.length();

    // Scan from right to left
    for (int i = len - 1; i >= 0; i--) {
        char c = prefix[i];

        // If digit, push numeric value
        if (isdigit(c)) {
            s.push(c - '0');
        }

        // If operator, pop two operands and apply operation
        else if (isOperator(c)) {
            int op1 = s.top(); s.pop();
            int op2 = s.top(); s.pop();
            int result = 0;

            // Perform operation
            switch (c) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
            }
            s.push(result);
        }
    }

    // Top of stack holds the evaluated result
    cout << "Evaluated Result: " << s.top() << endl;
}

// Main function with menu-driven program
int main() {
    Expression e;
    int choice;

    do {
        cout << "\n1. Prefix to Infix";
        cout << "\n2. Infix to Postfix";
        cout << "\n3. Evaluate Prefix";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        // Perform operation based on user choice
        switch (choice) {
            case 1: e.prefix_infix(); break;
            case 2: e.infix_postfix(); break;
            case 3: e.prefix_eval(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
