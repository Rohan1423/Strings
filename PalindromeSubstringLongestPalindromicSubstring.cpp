#include <iostream>
using namespace std;

// Expand around center
int expandFromCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1; // length of palindrome
}

string longestPalindrome(string s) {
    if (s.empty()) return "";

    int start = 0, end = 0;

    for (int i = 0; i < s.length(); i++) {
        int len1 = expandFromCenter(s, i, i);     // Odd length
        int len2 = expandFromCenter(s, i, i + 1); // Even length
        int len = max(len1, len2);

        if (len > end - start + 1) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    return s.substr(start, end - start + 1);
}

int main() {
    string s;
    cin >> s;

    string result = longestPalindrome(s);
    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}


// Every palindrome has a center → odd or even.

// Expand around center instead of checking all substrings.

// Keep track of start/end of max palindrome.

// Works for any string: odd/even length palindromes.