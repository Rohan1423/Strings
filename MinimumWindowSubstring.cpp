// Given two strings:

// s = "ADOBECODEBANC"

// t = "ABC"

// Find the smallest substring of s that contains all characters of t (including duplicates).

// Example:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"

// Approach (Sliding Window + Hash Map)
// Key Idea:

// Keep a window [left, right] in s.

// Expand right to include characters of t.

// When all characters of t are in the window → try shrinking left to make it smaller.

// Keep track of minimum length window.

#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

string minWindow(string s, string t) {  // T.C O(N + M) → N = length of s, M = length of t S.C O(N + M) → hash maps for window and t
    if (s.empty() || t.empty()) return "";

    unordered_map<char, int> freqT;
    for (char c : t)
        freqT[c]++;  // frequency of each char in t

    unordered_map<char, int> windowFreq;

    int required = freqT.size(); // unique chars in t
    int formed = 0;              // how many unique chars are fulfilled in current window

    int left = 0, right = 0;
    int minLen = INT_MAX, minLeft = 0;

    while (right < s.length()) {
        char c = s[right];
        windowFreq[c]++;

        // If this character fulfills the required count in t
        if (freqT.count(c) && windowFreq[c] == freqT[c])
            formed++;

        // Try shrinking the window from left
        while (left <= right && formed == required) {
            char temp = s[left];

            // Update minLen
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minLeft = left;
            }

            windowFreq[temp]--;
            if (freqT.count(temp) && windowFreq[temp] < freqT[temp])
                formed--;

            left++;
        }

        right++;
    }

    return (minLen == INT_MAX) ? "" : s.substr(minLeft, minLen);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    string result = minWindow(s, t);
    cout << "Minimum window substring: " << result << endl;

    return 0;
}