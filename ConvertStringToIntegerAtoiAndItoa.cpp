#include <iostream>
#include <climits>
#include <cctype>
using namespace std;

int myAtoi(string s) {  // T.C O(log n)  S.C O(1)
    int i = 0;
    int n = s.length();
    int sign = 1;
    long result = 0;

    // Skip leading spaces
    while (i < n && s[i] == ' ')
        i++;

    // Handle sign
    if (i < n && (s[i] == '-' || s[i] == '+')) {
        if (s[i] == '-')
            sign = -1;
        i++;
    }

    // Convert digits
    while (i < n && isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');

        // Handle overflow
        if (sign * result > INT_MAX)
            return INT_MAX;
        if (sign * result < INT_MIN)
            return INT_MIN;

        i++;
    }

    return sign * result;
}

int main() {
    string s = "12345";
    int num = myAtoi(s);

    cout << num << endl;
    return 0;
}

//For atoi:

// “Parse sign, skip spaces, accumulate digits using result = result*10 + digit, and handle overflow.”


// Leading spaces

// sign

// Overflow

// Invalid characters

// Empty string

// For itoa

// “Extract digits using modulo, convert to characters, append, and reverse.”

// Negative numbers

// Zero

// INT_MIN (special case!)