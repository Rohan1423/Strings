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

string minWindowASCII(string s, string t) {  // Optimized Minimum Window Substring (Using Array) T.C O(N) S.C O(1) (128 constant size array)
    if (s.empty() || t.empty()) return "";

    int freq[128] = {0};// ASCII size

    // Step 1: Store frequency of t
    for (char c : t)
        freq[c]++;

    int left = 0;
    int count = t.length();   // total chars we need to match
    int minLen = INT_MAX;
    int startIndex = 0;

    // Step 2: Expand window
    for (int right = 0; right < s.length(); right++) {

        // If this character is needed, reduce count
        if (freq[s[right]] > 0)
            count--;

        // Decrease freq for current character
        freq[s[right]]--;

        // Step 3: When all chars matched
        while (count == 0) {

            // Update minimum window
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                startIndex = left;
            }

            // Try to shrink window
            freq[s[left]]++;

            // If after incrementing, it becomes > 0,
            // that means we lost a required character
            if (freq[s[left]] > 0)
                count++;

            left++;
        }
    }

    return (minLen == INT_MAX) ? "" : s.substr(startIndex, minLen);
}


int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    string result = minWindow(s, t);
    cout << "Minimum window substring: " << result << endl;

    return 0;
}