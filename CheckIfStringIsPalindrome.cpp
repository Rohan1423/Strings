#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {  // Two Pointers T.C O(n) S.C O(1)
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false; // Mismatch found
        }
        left++;
        right--;
    }
    return true; // All characters matched
}

bool isPalindromeRec(string s, int left, int right) {  // Recursion T.C O(n) S.C O(n) stack
    if (left >= right) return true; // Base case
    if (s[left] != s[right]) return false; // Mismatch
    return isPalindromeRec(s, left + 1, right - 1);
}

int main() {
    string str = "racecar";
    if (isPalindrome(str))
        cout << str << " is a palindrome" << endl;
    else
        cout << str << " is not a palindrome" << endl;

    if (isPalindromeRec(str, 0, str.length() - 1))
        cout << str << " is a palindrome" << endl;
    else
        cout << str << " is not a palindrome" << endl;

    return 0;
}
