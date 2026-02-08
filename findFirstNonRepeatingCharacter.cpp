#include <iostream>
#include <string>
using namespace std;

char firstNonRepeating_Brute(string s) {  // Brute Force T.C O(n x n) S.C O(1)
    int n = s.length();

    for (int i = 0; i < n; i++) {
        bool isUnique = true;

        for (int j = 0; j < n; j++) {
            if (i != j && s[i] == s[j]) {
                isUnique = false;
                break;
            }
        }

        if (isUnique)
            return s[i];
    }
    return '\0';
}

// Better Approach Sorting......

char firstNonRepeating_Optimal(string s) {  // Optimal T.C O(n) S.C O(1)
    int freq[256] = {0}; // Creates an array to store frequency of each character Size 256 → all ASCII characters

    // Count frequency
    for (char ch : s)
        freq[ch]++;  // freq[97] = 2  -> 'a'

    // Find first non-repeating
    for (char ch : s) {  // If we returned in first loop → order would be wrong
        if (freq[ch] == 1)
            return ch;
    }

    // “Characters act as array indices using ASCII values, so freq[ch]++ increments the count of that character, and freq[ch] == 1 checks if it appeared exactly once.”

    return '\0';
}


int main() {
    string s = "aabbccde";
    char result = firstNonRepeating_Optimal(s);

    if (result != '\0')
        cout << "First non-repeating character: " << result << endl;
    else
        cout << "No non-repeating character found" << endl;

    return 0;
}
