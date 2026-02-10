#include <iostream>
#include <string>
using namespace std;

bool onlyDigits(const string& s) {  
    for (char ch : s) {
        if (ch < '0' || ch > '9')
            return false;
    }
    return !s.empty();  // empty string check
}

bool onlyLetters(const string& s) {
    for (char ch : s) {
        if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')))  // Using ASCII Checks
            return false;
    }
    return !s.empty();
}

string checkType(const string& s) {  // One-Function Combined Check
    bool digit = true, letter = true;

    for (char ch : s) {
        if (!isdigit(ch)) digit = false;  // Using Built-in Functions (isdigit, isalpha)
        if (!isalpha(ch)) letter = false;
    }

    if (digit) return "Only Digits";
    if (letter) return "Only Letters";
    return "Mixed";
}


int main() {
    string s = "123";

    if (onlyDigits(s))
        cout << "Contains only digits\n";
    else if (onlyLetters(s))
        cout << "Contains only letters\n";
    else
        cout << "Contains mixed characters\n";

    return 0;
}
