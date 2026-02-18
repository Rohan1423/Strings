// Given two strings s1 and s2, check if s2 is a rotation of s1.

// Example:

// s1 = "abcd"
// s2 = "cdab"   → TRUE (rotation)
// s2 = "acbd"   → FALSE

#include <iostream>
using namespace std;

bool isRotation(string s1, string s2) {  // T.C O(n) S.C O(n) (for temp string).
    if (s1.length() != s2.length())
        return false;

    string temp = s1 + s1;  // s2 must be a substring of (s1 + s1) 

    return temp.find(s2) != string::npos;
}

// If you rotate "abcd":

// abcd
// bcda
// cdab
// dabc

// All possible rotations appear inside:

// abcdabcd

bool isRotationWithoutExtraString(string s1, string s2) {  // (Without Creating Extra String)  T.C: O(n²) S.C: O(1)
    if (s1.length() != s2.length())
        return false;

    int n = s1.length();

    for (int i = 0; i < n; i++) {
        bool match = true;
        for (int j = 0; j < n; j++) {
            if (s1[(i + j) % n] != s2[j]) {  // It makes the string circular Suppose i = 2 -> We want rotation starting at index 2 -> from c d a till b
                match = false;               // abcd vs cdab ❌  cdab vs cdab ✅
                break;
            }
        }
        if (match) return true;
    }

    return false;
}

int main() {
    string s1 = "abcd";
    string s2 = "cdab";

    if (isRotationWithoutExtraString(s1, s2))
        cout << "Yes, it is a rotation";
    else
        cout << "No, not a rotation";

    return 0;
}

// For optimal solution”

// Use:

// (s1 + s1).find(s2)
